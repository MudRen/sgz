#include <mudlib.h>
#include <ansi.h>
#include <edit.h>
#include <menu.h>

#define UNION_D "/daemons/union_d.c"

inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;

MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;

private string who;
private int auto;

void do_add();
void do_type();
void do_ev(string str);
void do_view(string str);
void do_prove(string str);
void do_comment(string str);
void do_whom(string str);
void do_delete(string str);
void do_reason();
void do_suggest();
void do_list();

void get_reason(string *reason);
void get_suggest(string *reason);
void get_type(mapping types, string choice);
void get_prove(string ppl, string str);
void get_comment(string ppl, string *reason);
void select_mode(string str);

void create()
{
    who	= this_body()->query_primary_id();
    auto= 0;
    toplevel = new_menu("\n" + mud_name() + "投诉/案件菜单");
    quit_item = new_menu_item("退出", (:quit_menu_application:), "q");
    seperator = new_seperator("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("新的投诉", (: do_add :), "a"));
    add_menu_item(toplevel, new_menu_item("案件类型", (: do_type :), "t"));
    add_menu_item(toplevel, new_menu_item("投诉谁？",
        (: get_input_then_call, (: do_whom :), "请输入你要投诉人的id：" :), "w"));
    add_menu_item(toplevel, new_menu_item("提供证人",
        (: get_input_then_call, (: do_ev :),  "请输入你的证人的id：" :), "e"));
    add_menu_item(toplevel, new_menu_item("陈述理由", (: do_reason :), "r"));
    add_menu_item(toplevel, new_menu_item("建议裁决", (: do_suggest :), "s"));
    add_menu_item(toplevel, new_menu_item("案件列表", (: do_list :), "l"));
    add_menu_item(toplevel, new_menu_item("案件删除", 
	(: get_input_then_call, (: do_delete :), "请输入要删除的案件id：" :), "d"));
    add_menu_item(toplevel, new_menu_item("查询细节",
        (: get_input_then_call, (: do_view :), "请输入要查询的案件id：" :), "v"));
    add_menu_item(toplevel, new_menu_item("为案件作证",
        (: get_input_then_call, (: do_prove :), "请输入要作证的案件id：" :), "p"));
    add_menu_item(toplevel, new_menu_item("发表意见",
        (: get_input_then_call, (: do_comment :), "请输入要发表意见的案件id：" :), "c"));
    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, seperator);

    set_menu_prompt (toplevel, "输入指令[aedlstw|cpv|q]:~> ");
}
void start_menu(){
    init_menu_application( toplevel );
}
void do_add()
{
    if ( UNION_D->add_case(who)==1 ) {
        write("你已经有过一次投诉记录在案了。\n");
        return;
    }
    write("好，接受你的投诉，请认真填写本表格。\n");
    UNION_D->add_case(who, "");
    write("如果你不熟悉本系统，请输入yes进入引导模式。\n");
    get_input_then_call((: select_mode :), "请输入yes或者no:");
}
void select_mode(string str)
{
    if ( str&&str=="yes" ) {
	write("进入引导模式。\n");
        auto = 1;
	do_type();
    }
}
void do_reason()
{
    string *original;
    if ( stringp(UNION_D->query_case(who, "reason")) )
        original = explode(UNION_D->query_case(who, "reason"), "\n");
    else
        original = ({ });
    if ( auto == 1 ) write("请输入你的理由，不得长于十行！\n");
    new(EDIT_OB, EDIT_TEXT, original, (: get_reason :) );
}
void get_reason(string *reason)
{
    write("自陈已被记录。\n");
    if ( sizeof(reason)>10 ) reason = reason[0..10];
    UNION_D->set_case(who, "reason", implode(reason, "\n") );
    if ( auto == 1 ) do_suggest();
    else prompt_then_return();
}
void do_type()
{
    int i;
    string str = "";
    mapping types;

    if ( stringp(UNION_D->query_case(who, "type"))&&UNION_D->query_case(who, "type")!="" ) {
	write("不可以随便更改案件类型！\n");
	return;
    }
    types = UNION_D->query_types();
    for( i=0; i<sizeof(types); i++ )
        str += (i+1)+") " + values(types)[i] + "\n";
    write(str);
    get_input_then_call( (: get_type, types :), "请选择你的案件类型：");
}
void get_type(mapping types, string choice)
{
    int i;

    if ( !choice ) {
        write("非法选择。\n");
        return;
    }
    i = to_int(choice)-1;
    if ( i<0||i>sizeof(types)-1 ) {
        write("选择超出范围。\n");
    } else {
    	UNION_D->set_case(who, "type", keys(types)[i]);
    	write("已被记录。\n");
    }
    if ( auto == 1 ) 
	get_input_then_call( (: do_whom :), "请输入你要投诉人的id：");
    else  prompt_then_return();
}
void do_whom(string str)
{
    if ( UNION_D->query_case(who, "whom")!=""&&stringp(UNION_D->query_case(who, "whom")) )
        write("不可以随便更改被投诉人\n");
    else if ( !CHAR_D->char_exist(str) ) 
        write("本游戏中并无此角色！\n");
    else {
	UNION_D->set_case(who, "whom", str);
	write("已被记录。\n");
    }
    if ( auto == 1 ) 
	get_input_then_call((: do_ev :),"请输入你的证人的id：" );
    else    prompt_then_return();
}
void do_suggest()
{
    string *original;
    if ( stringp(UNION_D->query_case(who, "solution")) )
   	original = explode(UNION_D->query_case(who, "solution"), "\n");
    else
	original = ({ });
    if ( auto == 1 ) write("请输入你所期待的处置，不得长于十行！\n");
    new(EDIT_OB, EDIT_TEXT, original, (: get_suggest :) );
}
void get_suggest(string *reason)
{
    write("已被记录。\n");
    if ( sizeof(reason)>10 ) reason = reason[0..10];
    UNION_D->set_case(who, "solution", implode(reason, "\n") );
    if ( auto == 1 ) {
	write("%^H_CYAN%^你已经完成了本表格，请耐心等待审理，\n");
	write("再次感谢您的合作！%^RESET%^\n");
        auto = 0;
    }
    prompt_then_return();
}
void do_ev(string str)
{
    string *ids;
    mapping m;
   
    m = UNION_D->query_case(who, "ev");
    if( mapp(m)&&sizeof(m) ) 
	write("在案件审理过程中不可以更换证人！\n");
    else {
	m = ([ ]);
    	if ( stringp(str)&&str!="" ) {
            ids = explode(str, ",");
            if ( sizeof(ids)>2 ) ids = ids[0..1];
            foreach( string s in ids )
            	m[s] = -1;
        }
    	UNION_D->set_case(who, "ev", m );
    	write("已被记录。\n");
    }
    if ( auto == 1 ) do_reason();
    else prompt_then_return();
}
void do_list()
{
    write(UNION_D->query_case_list());
    prompt_then_return();
}
void do_delete(string str)
{
    string ret;

    if ( !wizardp(who) ) ret = "只有巫师才可以删除投诉！\n";
    else if ( UNION_D->remove_case(str)==1 ) ret = "此人没有投诉在案！\n";
    else ret = "相关的记录已经撤消了。\n";
    write( ret );
    prompt_then_return();
}
void do_prove(string str)
{
    mapping cases, ev;
  
    cases = UNION_D->query_case( str );
    if ( !mapp(cases)||!sizeof(cases) )
	write("此人没有投诉在案！\n");
    else if ( !mapp(ev=cases["ev"])||!sizeof(ev) )
	write("此案没有传召证人！\n");
    else if ( member_array(who, keys(ev))==-1 )
        write("投诉人并未要求你作证！\n");
    else if ( ev[who] != -1 )
	write("你已经作过证了，再次感谢！\n");
    else {
	write("%^H_RED%^你的证词可能成为执法的依据，请慎重！%^RESET%^\n");
        write("-2表示反对，0表示中立，1表示赞同。\n");
        get_input_then_call( (: get_prove, str :), "请输入你的意见：");
    }
    return;
}
void get_prove(string ppl, string str)
{
    int i;
    mapping ev;
    
    ev = UNION_D->query_case(ppl, "ev");
    if ( !mapp(ev) ) ev = ([ ]);
    i = to_int(str);
    ev[who] = i;
    UNION_D->set_case(ppl, "ev", ev);
    write("感谢您为本案作证！\n");
    prompt_then_return();
}
void do_comment(string str)
{
    mapping cases, cc;

    cases = UNION_D->query_case( str );
    if ( !mapp(cases)||!sizeof(cases) ){
        write("此人没有投诉在案！\n");
	return;
    }
    if ( !mapp(cc=cases["comment"]) ) cc = ([ ]);
    if ( stringp(cc[who]) ){
	write("你已经发表过意见了，再次感谢！\n");
	return;
    }
    new(EDIT_OB, EDIT_TEXT, 0, (: get_comment, str :) );
}
void get_comment(string ppl, string *reason)
{
    mapping cc;

    write("感谢你发表的意见！\n");
    cc = UNION_D->query_case(ppl, "comment");
    if ( !mapp(cc) ) cc = ([ ]);  
    if ( sizeof(reason)>4 ) reason = reason[0..3];
    cc[who] = implode(reason, "\n");
    UNION_D->set_case(ppl, "comment", cc );
    prompt_then_return();
}    
void do_view(string str)
{
    int i;
    mapping m;

    if ( !mapp(m=UNION_D->query_case(str)) ){
	write("此人没有投诉在案！\n");
	return;
    };
    if ( wizardp(who) ) i = 1;
    if ( UNION_D->query_is_jury(who) == 1 ) i = 1;
    if ( mapp(m=m["ev"])&&member_array(who, keys(m))!=-1 ) i = 1;
    write(UNION_D->view_case(str, i));
    prompt_then_return();
}

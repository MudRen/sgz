#include <mudlib.h>
#include <ansi.h>
#include <edit.h>

#define UNION_D "/daemons/union_d.c"

inherit LIVING;
inherit M_CHAR;

private string ppl;

void remove_ppl();
void check_case(string who);
void check_cancel(string who);
void get_type();
void answer_get_type(mapping types, string got);
void get_ev(string got);
void get_whom(string got);
void get_reason(string *reason);
void get_conclusion(string *con);

void setup()
{
    object cloth;
    cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
    cloth->move(this_object());
    cloth->do_wear();

    set_name("shuji guan", "书记官");
    add_id("recorder");
    add_id("guan");
    add_id("shuji");
    set_gender(1);
    set_age(20);
    set_in_room_desc(HIY+"〖东汉宫廷〗"+HIC+"「有事就向我投诉」"+HIG+"书记官"+NOR+"(shuji guan)");
    set_proper_name(HIY+"书记"+NOR+"(shuji guan)");

    add_question("case", "case");
    add_ask_str("case", "$N向$T做了一个揖，道：$s想要投诉，不知当否？\n");
    add_question("cancel", "cancel");
    add_ask_str("cancel", "$N向$T做了一个揖，道：$s想要撤诉，不知当否？\n");
    add_question("list","list");
    add_ask_str("list","$N向$T做了一个揖，道：大人可否告之有什么投诉吗？\n");
}
mixed special_answer(object ob, string str)
{
    if ( str == "cancel" ) 
	check_cancel( ob->query_primary_id() );
    else if ( str == "list" ) 
	write(UNION_D->query_case_list());
    else if ( stringp(ppl)&&ppl!="" )
	simple_action("$N道：请稍侯片刻。\n");
    else if ( str == "case" ) 
	check_case( ob->query_primary_id() );
    else return ::special_answer(ob, str);
}
void remove_ppl()
{
    ppl = "";
}
void check_cancel(string who)
{
    if ( UNION_D->remove_case(who)==1 ) {
       targetted_action("$N翻了翻记录，摇头道：$m$R从未向下官投诉过呀。\n",this_body()); 
    } else if ( UNION_D->remove_case(who)==2 ) {
       targetted_action("$N拿了支朱笔将相关的记录划去，道：好的，$m$R的投诉已经撤消了。\n",this_body());
    } else
        SGSYS("error in remove case for "+who+" !");
}
void check_case(string who)
{
    if ( UNION_D->add_case(who)==1 ) {
	targetted_action("$N摇头道：$m$R已经有过一次投诉记录在案了。\n",this_body());
    } else {
        ppl = who;
        targetted_action("$N点头道：好，下官接受$m$R的投诉，请认真填写以下表格。\n",this_body());
        get_type();
        call_out("remove_ppl", 300 );
    }
}
void get_type()
{
    int i;
    mapping types;
    object o;
    string str = "请选择你的案件类型：\n";

    if ( !objectp(o=find_body(ppl)) ) return;
    types = UNION_D->query_types();
    for( i=0; i<sizeof(types); i++ )
	str += (i+1)+") " + values(types)[i] + "\n";
    write(str);
    o->modal_push( (: answer_get_type, types :), "输入你的选择：");
}
void answer_get_type(mapping types, string got)
{
   int i;
   object o = find_body(ppl);
   if ( !objectp(o) ) { remove_ppl(); return; }
   o->modal_pop();
   if ( !got ) {
	simple_action("非法选择。\n");
	remove_ppl();
        return;
   }
   i = to_int(got)-1;
   if ( i<0||i>sizeof(types)-1 ) {
	simple_action("选择超出范围。\n");
	remove_ppl();
        return;
   }
   UNION_D->set_case(ppl, "type", keys(types)[i]);
   simple_action("$N点了点头。\n");
   o->modal_push( (: get_whom :), "你想要投诉何人或何国：" );
}
void get_whom(string got)
{
    object o = find_body(ppl);
    if ( !objectp(o) ) { remove_ppl(); return; }
    o->modal_pop();
    UNION_D->set_case(ppl, "whom", got);
    o->modal_push( (: get_ev :), "请提供证人：" );
}
void get_ev(string got)
{
    string *ids;
    mapping m = ([ ]);
    object o = find_body(ppl);

    if ( !objectp(o) ) { remove_ppl(); return; }
    o->modal_pop();
    if ( stringp(got)&&got!="" ) { 
    	ids = explode(got, ",");
        foreach( string s in ids )
            m[s] = -1;
    }
    UNION_D->set_case(ppl, "ev", m );
    write("请陈述你的理由（不超过一百字）：\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: get_reason :) );
}
void get_reason(string *reason)
{
    write("自陈已被记录。\n");
    if ( sizeof(reason)>20 ) reason = reason[0..10];
    UNION_D->set_case(ppl, "reason", implode(reason, "\n") );
    write("请输入你的建议裁决（即投诉获准后将采取的措施，不超过五十字）：\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: get_conclusion :) );
}
void get_conclusion(string *con)
{
    write("建议裁决已被记录。\n");
    if ( sizeof(con)>20 ) con = con[0..10];
    UNION_D->set_case(ppl, "solution", implode(con, "\n") );
    write("谢谢你的配合，请静侯裁决。\n");
    remove_ppl();
}

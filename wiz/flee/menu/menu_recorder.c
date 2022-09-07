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
    toplevel = new_menu("\n" + mud_name() + "Ͷ��/�����˵�");
    quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
    seperator = new_seperator("\n��������������������������������������������������������������������������\n");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("�µ�Ͷ��", (: do_add :), "a"));
    add_menu_item(toplevel, new_menu_item("��������", (: do_type :), "t"));
    add_menu_item(toplevel, new_menu_item("Ͷ��˭��",
        (: get_input_then_call, (: do_whom :), "��������ҪͶ���˵�id��" :), "w"));
    add_menu_item(toplevel, new_menu_item("�ṩ֤��",
        (: get_input_then_call, (: do_ev :),  "���������֤�˵�id��" :), "e"));
    add_menu_item(toplevel, new_menu_item("��������", (: do_reason :), "r"));
    add_menu_item(toplevel, new_menu_item("����þ�", (: do_suggest :), "s"));
    add_menu_item(toplevel, new_menu_item("�����б�", (: do_list :), "l"));
    add_menu_item(toplevel, new_menu_item("����ɾ��", 
	(: get_input_then_call, (: do_delete :), "������Ҫɾ���İ���id��" :), "d"));
    add_menu_item(toplevel, new_menu_item("��ѯϸ��",
        (: get_input_then_call, (: do_view :), "������Ҫ��ѯ�İ���id��" :), "v"));
    add_menu_item(toplevel, new_menu_item("Ϊ������֤",
        (: get_input_then_call, (: do_prove :), "������Ҫ��֤�İ���id��" :), "p"));
    add_menu_item(toplevel, new_menu_item("�������",
        (: get_input_then_call, (: do_comment :), "������Ҫ��������İ���id��" :), "c"));
    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, seperator);

    set_menu_prompt (toplevel, "����ָ��[aedlstw|cpv|q]:~> ");
}
void start_menu(){
    init_menu_application( toplevel );
}
void do_add()
{
    if ( UNION_D->add_case(who)==1 ) {
        write("���Ѿ��й�һ��Ͷ�߼�¼�ڰ��ˡ�\n");
        return;
    }
    write("�ã��������Ͷ�ߣ���������д�����\n");
    UNION_D->add_case(who, "");
    write("����㲻��Ϥ��ϵͳ��������yes��������ģʽ��\n");
    get_input_then_call((: select_mode :), "������yes����no:");
}
void select_mode(string str)
{
    if ( str&&str=="yes" ) {
	write("��������ģʽ��\n");
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
    if ( auto == 1 ) write("������������ɣ����ó���ʮ�У�\n");
    new(EDIT_OB, EDIT_TEXT, original, (: get_reason :) );
}
void get_reason(string *reason)
{
    write("�Գ��ѱ���¼��\n");
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
	write("�����������İ������ͣ�\n");
	return;
    }
    types = UNION_D->query_types();
    for( i=0; i<sizeof(types); i++ )
        str += (i+1)+") " + values(types)[i] + "\n";
    write(str);
    get_input_then_call( (: get_type, types :), "��ѡ����İ������ͣ�");
}
void get_type(mapping types, string choice)
{
    int i;

    if ( !choice ) {
        write("�Ƿ�ѡ��\n");
        return;
    }
    i = to_int(choice)-1;
    if ( i<0||i>sizeof(types)-1 ) {
        write("ѡ�񳬳���Χ��\n");
    } else {
    	UNION_D->set_case(who, "type", keys(types)[i]);
    	write("�ѱ���¼��\n");
    }
    if ( auto == 1 ) 
	get_input_then_call( (: do_whom :), "��������ҪͶ���˵�id��");
    else  prompt_then_return();
}
void do_whom(string str)
{
    if ( UNION_D->query_case(who, "whom")!=""&&stringp(UNION_D->query_case(who, "whom")) )
        write("�����������ı�Ͷ����\n");
    else if ( !CHAR_D->char_exist(str) ) 
        write("����Ϸ�в��޴˽�ɫ��\n");
    else {
	UNION_D->set_case(who, "whom", str);
	write("�ѱ���¼��\n");
    }
    if ( auto == 1 ) 
	get_input_then_call((: do_ev :),"���������֤�˵�id��" );
    else    prompt_then_return();
}
void do_suggest()
{
    string *original;
    if ( stringp(UNION_D->query_case(who, "solution")) )
   	original = explode(UNION_D->query_case(who, "solution"), "\n");
    else
	original = ({ });
    if ( auto == 1 ) write("�����������ڴ��Ĵ��ã����ó���ʮ�У�\n");
    new(EDIT_OB, EDIT_TEXT, original, (: get_suggest :) );
}
void get_suggest(string *reason)
{
    write("�ѱ���¼��\n");
    if ( sizeof(reason)>10 ) reason = reason[0..10];
    UNION_D->set_case(who, "solution", implode(reason, "\n") );
    if ( auto == 1 ) {
	write("%^H_CYAN%^���Ѿ�����˱���������ĵȴ�����\n");
	write("�ٴθ�л���ĺ�����%^RESET%^\n");
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
	write("�ڰ�����������в����Ը���֤�ˣ�\n");
    else {
	m = ([ ]);
    	if ( stringp(str)&&str!="" ) {
            ids = explode(str, ",");
            if ( sizeof(ids)>2 ) ids = ids[0..1];
            foreach( string s in ids )
            	m[s] = -1;
        }
    	UNION_D->set_case(who, "ev", m );
    	write("�ѱ���¼��\n");
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

    if ( !wizardp(who) ) ret = "ֻ����ʦ�ſ���ɾ��Ͷ�ߣ�\n";
    else if ( UNION_D->remove_case(str)==1 ) ret = "����û��Ͷ���ڰ���\n";
    else ret = "��صļ�¼�Ѿ������ˡ�\n";
    write( ret );
    prompt_then_return();
}
void do_prove(string str)
{
    mapping cases, ev;
  
    cases = UNION_D->query_case( str );
    if ( !mapp(cases)||!sizeof(cases) )
	write("����û��Ͷ���ڰ���\n");
    else if ( !mapp(ev=cases["ev"])||!sizeof(ev) )
	write("�˰�û�д���֤�ˣ�\n");
    else if ( member_array(who, keys(ev))==-1 )
        write("Ͷ���˲�δҪ������֤��\n");
    else if ( ev[who] != -1 )
	write("���Ѿ�����֤�ˣ��ٴθ�л��\n");
    else {
	write("%^H_RED%^���֤�ʿ��ܳ�Ϊִ�������ݣ������أ�%^RESET%^\n");
        write("-2��ʾ���ԣ�0��ʾ������1��ʾ��ͬ��\n");
        get_input_then_call( (: get_prove, str :), "��������������");
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
    write("��л��Ϊ������֤��\n");
    prompt_then_return();
}
void do_comment(string str)
{
    mapping cases, cc;

    cases = UNION_D->query_case( str );
    if ( !mapp(cases)||!sizeof(cases) ){
        write("����û��Ͷ���ڰ���\n");
	return;
    }
    if ( !mapp(cc=cases["comment"]) ) cc = ([ ]);
    if ( stringp(cc[who]) ){
	write("���Ѿ����������ˣ��ٴθ�л��\n");
	return;
    }
    new(EDIT_OB, EDIT_TEXT, 0, (: get_comment, str :) );
}
void get_comment(string ppl, string *reason)
{
    mapping cc;

    write("��л�㷢��������\n");
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
	write("����û��Ͷ���ڰ���\n");
	return;
    };
    if ( wizardp(who) ) i = 1;
    if ( UNION_D->query_is_jury(who) == 1 ) i = 1;
    if ( mapp(m=m["ev"])&&member_array(who, keys(m))!=-1 ) i = 1;
    write(UNION_D->view_case(str, i));
    prompt_then_return();
}

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

    set_name("shuji guan", "��ǹ�");
    add_id("recorder");
    add_id("guan");
    add_id("shuji");
    set_gender(1);
    set_age(20);
    set_in_room_desc(HIY+"��������͢��"+HIC+"�����¾�����Ͷ�ߡ�"+HIG+"��ǹ�"+NOR+"(shuji guan)");
    set_proper_name(HIY+"���"+NOR+"(shuji guan)");

    add_question("case", "case");
    add_ask_str("case", "$N��$T����һ��Ҿ������$s��ҪͶ�ߣ���֪����\n");
    add_question("cancel", "cancel");
    add_ask_str("cancel", "$N��$T����һ��Ҿ������$s��Ҫ���ߣ���֪����\n");
    add_question("list","list");
    add_ask_str("list","$N��$T����һ��Ҿ���������˿ɷ��֮��ʲôͶ����\n");
}
mixed special_answer(object ob, string str)
{
    if ( str == "cancel" ) 
	check_cancel( ob->query_primary_id() );
    else if ( str == "list" ) 
	write(UNION_D->query_case_list());
    else if ( stringp(ppl)&&ppl!="" )
	simple_action("$N�������Ժ�Ƭ�̡�\n");
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
       targetted_action("$N���˷���¼��ҡͷ����$m$R��δ���¹�Ͷ�߹�ѽ��\n",this_body()); 
    } else if ( UNION_D->remove_case(who)==2 ) {
       targetted_action("$N����֧��ʽ���صļ�¼��ȥ�������õģ�$m$R��Ͷ���Ѿ������ˡ�\n",this_body());
    } else
        SGSYS("error in remove case for "+who+" !");
}
void check_case(string who)
{
    if ( UNION_D->add_case(who)==1 ) {
	targetted_action("$Nҡͷ����$m$R�Ѿ��й�һ��Ͷ�߼�¼�ڰ��ˡ�\n",this_body());
    } else {
        ppl = who;
        targetted_action("$N��ͷ�����ã��¹ٽ���$m$R��Ͷ�ߣ���������д���±��\n",this_body());
        get_type();
        call_out("remove_ppl", 300 );
    }
}
void get_type()
{
    int i;
    mapping types;
    object o;
    string str = "��ѡ����İ������ͣ�\n";

    if ( !objectp(o=find_body(ppl)) ) return;
    types = UNION_D->query_types();
    for( i=0; i<sizeof(types); i++ )
	str += (i+1)+") " + values(types)[i] + "\n";
    write(str);
    o->modal_push( (: answer_get_type, types :), "�������ѡ��");
}
void answer_get_type(mapping types, string got)
{
   int i;
   object o = find_body(ppl);
   if ( !objectp(o) ) { remove_ppl(); return; }
   o->modal_pop();
   if ( !got ) {
	simple_action("�Ƿ�ѡ��\n");
	remove_ppl();
        return;
   }
   i = to_int(got)-1;
   if ( i<0||i>sizeof(types)-1 ) {
	simple_action("ѡ�񳬳���Χ��\n");
	remove_ppl();
        return;
   }
   UNION_D->set_case(ppl, "type", keys(types)[i]);
   simple_action("$N���˵�ͷ��\n");
   o->modal_push( (: get_whom :), "����ҪͶ�ߺ��˻�ι���" );
}
void get_whom(string got)
{
    object o = find_body(ppl);
    if ( !objectp(o) ) { remove_ppl(); return; }
    o->modal_pop();
    UNION_D->set_case(ppl, "whom", got);
    o->modal_push( (: get_ev :), "���ṩ֤�ˣ�" );
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
    write("�����������ɣ�������һ���֣���\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: get_reason :) );
}
void get_reason(string *reason)
{
    write("�Գ��ѱ���¼��\n");
    if ( sizeof(reason)>20 ) reason = reason[0..10];
    UNION_D->set_case(ppl, "reason", implode(reason, "\n") );
    write("��������Ľ���þ�����Ͷ�߻�׼�󽫲�ȡ�Ĵ�ʩ����������ʮ�֣���\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: get_conclusion :) );
}
void get_conclusion(string *con)
{
    write("����þ��ѱ���¼��\n");
    if ( sizeof(con)>20 ) con = con[0..10];
    UNION_D->set_case(ppl, "solution", implode(con, "\n") );
    write("лл�����ϣ��뾲��þ���\n");
    remove_ppl();
}

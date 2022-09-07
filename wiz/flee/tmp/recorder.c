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
void answer_get_type(string *types, string got);
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

    set_name("shuji guan", "���");
    add_id("recorder");
    add_id("guan");
    add_id("shuji");
    set_gender(1);
    set_age(20);
    set_proper_name(HIY+"���"+NOR+"(shuji guan)");
    set_in_room_desc(HIY+"���"+NOR+"(shuji guan)");

    add_question("case", "case");
    add_ask_str("case", "i want to add a case\n");
    add_question("cancel", "cancel");
    add_ask_str("cancel", "i want to cancel a case\n");
}
mixed special_answer(object ob, string str)
{
    if ( str == "cancel" ) 
	check_cancel( ob->query_primary_id() );
    else if ( str == "list" ) 
	UNION_D->query_case_list();
    else if ( stringp(ppl)&&ppl!="" )
	simple_action("$N sigh: please wait for a while.\n");
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
	simple_action("$N is surprised: u never report a case!\n"); 
    } else if ( UNION_D->remove_case(who)==2 ) {
        simple_action("$N: ok, removed!\n");
    } else
        SGSYS("error in remove case for "+who+" !");
}
void check_case(string who)
{
    if ( UNION_D->add_case(who)==1 ) {
	simple_action("$N shakes his head: u got one case already\n");
    } else {
        ppl = who;
        simple_action("$N nods and say: accepted\n");
        get_type();
        call_out("remove_ppl", 300 );
    }
}
void get_type()
{
    int i;
    mapping types;
    object o;
    string str = "please choose:\n";

    if ( !objectp(o=find_body(ppl)) ) return;
    types = UNION_D->query_types();
    for( i=0; i<sizeof(types); i++ )
	str += (i+1)+") " + values(types)[i] + "\n";
    write(str);
    o->modal_push( (: answer_get_type, keys(types) :), "input u choice: >");
}
void answer_get_type(string *types, string got)
{
   int i;
   object o = find_body(ppl);
   if ( !objectp(o) ) { remove_ppl(); return; }
   o->modal_pop();
   if ( !got ) {
	simple_action("no input\n");
	remove_ppl();
        return;
   }
   i = to_int(got)-1;
   if ( i<0||i>sizeof(types)-1 ) {
	simple_action("input out of range\n");
	remove_ppl();
        return;
   }
   UNION_D->set_case(ppl, "type", types[i]);
   simple_action("$N nods\n");
   o->modal_push( (: get_whom :), "against who > " );
}
void get_whom(string got)
{
    object o = find_body(ppl);
    if ( !objectp(o) ) { remove_ppl(); return; }
    o->modal_pop();
    UNION_D->set_case(ppl, "whom", got);
    o->modal_push( (: get_ev :), "give proof > " );
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
    write("please input ur reason\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: get_reason :) );
}
void get_reason(string *reason)
{
    write("ok, reason got \n");
    if ( sizeof(reason)>20 ) reason = reason[0..19];
    UNION_D->set_case(ppl, "reason", implode(reason, "\n") );
    write("please input ur comments\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: get_conclusion :) );
}
void get_conclusion(string *con)
{
    write("ok, conclusion got \n");
    if ( sizeof(con)>20 ) con = con[0..19];
    UNION_D->set_case(ppl, "solution", implode(con, "\n") );
    write("thank u for ur report!\n");
    remove_ppl();
}

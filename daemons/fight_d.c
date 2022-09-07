// fight_d.c this is used to control fight
// by fire in March 1999
#include <combat.h>
inherit __DIR__+"fight_d/formula";


#define IAMNOTCHAR "�����������º�ʤ֮�ˣ���ϲ�򶷡�\n"
#define IAMBUSY "������æ���أ�����ʱ�������书��"

#define IAMFIGHTING "���ڴ��ء�\n"

#define ASKFIGHT "$N��$Tһ���ֵ���$M���ţ�Ը��$R���������书��\n"
#define CONFIRMFIGHT "$N��$T���ͷ��������Ȼ$R���ߴͽ̣�$s�����㡣\n"
#include <security.h>
#include <classes.h>


inherit M_DAEMON_DATA;

private mapping fights = ([]);
private string *f_ids=({});
mixed can_u_fight(object o);
mixed can_i_fight(object o);

mixed fight_peer=([]);


void set_fight_peer(string a_id,string d_id)
{
fight_peer[a_id] = d_id;
}

string get_fight_peer(string a_id)
{
if (!fight_peer[a_id]) return "";
else return fight_peer[a_id];
}


int get_fight_type(string p_id)
{
	if(!fights[p_id]) return 0;
	return fights[p_id]["type"];
}
mixed get_fight(string p_id) {
	if((!p_id)||(p_id==""))
		return fights;
	if(p_id=="list") return f_ids;
	return fights[p_id];
}

void check_fight() {
	object o;
	remove_call_out("check_fight");
	call_out("check_fight",20);
	if(!sizeof(f_ids)) return;
	foreach(string id in f_ids) {
		o=CHAR_D->find_char(id);
		if((!objectp(o))||(!o->is_fighting())) {
			map_delete(fights,id);
		}
	}
	f_ids=keys(fights);
	save_me();
}
void create() {
	m_daemon_data::create();
	remove_call_out("check_fight");
	call_out("check_fight",20);
	fight_peer=([]);
}

mixed add_fight(string a,mixed b,int type)
{
	fights[a]=([]);
	fights[a]["target"]=b;
	fights[a]["type"]=type;
	f_ids=keys(fights);
    save_me();
}

void remove_fight(string id)
{
    if ( !fights[id] )
        return;
    map_delete(fights, id);
	f_ids=keys(fights);
    save_me();
}

mixed confirm_fight(object a, object b) 
{
	string a_id,b_id;
	if(!objectp(a)) return;
	if(!objectp(b)) return;
	b->targetted_action(CONFIRMFIGHT,a);
	a_id=a->query_id()[0];
	b_id=b->query_id()[0];
	add_fight(a_id,({b_id}),COMBAT_FIGHT); // 1 is common fight
	add_fight(b_id,({a_id}),COMBAT_FIGHT);
	b->start_fight(a);
	map_delete(fight_peer,a_id);
	map_delete(fight_peer,b_id);
}

mixed can_fight(object a,object b) {
	mixed ret;
	ret=can_i_fight(a);
	if(!ret) ret="��֪Ϊʲô���㲻��򶷡�\n";
	if(stringp(ret)) {
		write(ret);
		return;
	}
	a->targetted_action(ASKFIGHT,b);
	ret=can_u_fight(b);
	if(!ret) ret="$N��$T������֪Ϊʲô���Ҳ���򶷡�\n";
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(b,a,ret,1);
		return ret;
	                 }
	call_out("confirm_fight",1,a,b);
	return 1;
}

mixed can_u_fight(object o) {
	string p_id;
	p_id=o->query_id()[0];
	if(!CHAR_D->char_exist(p_id)) return "$N��$T����$s"+IAMNOTCHAR;
	if((CHAR_D->get_char(p_id,"is_tmp"))&&(!CHAR_D->get_char(p_id,"if_fighter")))
		return "$N��$T����$s"+IAMNOTCHAR;
	if(CHAR_D->get_char(p_id,"task")) return "$N��$T����$s"+IAMBUSY;
	if(o->is_fighting()) return "$N��$T����$s"+IAMFIGHTING;
	return 1; // ok i can fight
}
mixed can_i_fight(object o) {
	string p_id;
	object env,wep;
	p_id=o->query_id()[0];
	if(!CHAR_D->char_exist(p_id)) return "��"+IAMNOTCHAR;
	if(CHAR_D->get_char(p_id,"task")) return "��"+IAMBUSY;
	if(CHAR_D->get_char(p_id,"body")=="gini") 
            { this_body()->simple_action("$N�����Բ������ˣ���ܻ������Լ��ϰ�!\n");
               return "hoho\n";
            }
	if(o->is_fighting()) return "��"+IAMFIGHTING;
	return 1; // ok i can fight
} 

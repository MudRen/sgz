// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <sanguo.h>
#include "mudlib.h"
#include <bodyslots.h>

inherit CONTAINER;
inherit __DIR__ "living/grammar";
inherit __DIR__ "living/messages";
inherit __DIR__ "living/state_of_mind";
inherit M_ASK;
inherit M_ANSWER;
// inherit M_SKILLS;

inherit M_SGGIFT;
/* This is a pure 'living' object, not what is traditionally meant
 * by a living object on LPmuds.  Note that find_living() won't
 * necessarily find it b/c the driver may not even know it's
 * alive.  (Why the driver keeps track of livings is beyond me ...)
 * [ed note: it doesn't any more; find_living() doesn't exist]
 * This is an object than can hold things and do actions.  If you
 * want it to be able to fight, inherit MONSTER instead.
 */

private string ename, cname;


private static int p_accept_money;
int query_accept_money()
{ return p_accept_money;
}
void set_accept_money(int i)
{
   p_accept_money=i;
}
void mudlib_setup()
{
    ::mudlib_setup();
    set_max_capacity(100);
    set_def_msgs("living-default");
   clear_flag(TRANSPARENT);
}

string query_name() { return (cname ? cname + "(" + ename + ")"
                             : ename) ; }

void set_name(string n, string chinese_name) {
    if (ename) remove_id(lower_case(n));
    ename = n;
    add_id(lower_case(n));
    if (chinese_name) {
        remove_id(chinese_name);
        cname = chinese_name;
        add_chinese_id( cname );
    }
}

string in_room_desc() {
  return query_in_room_desc();
}

object query_room() // return the room of the living
{
	object env=environment();
	if(!objectp(env)) { SGSYS(this_object()->short()+" has no room"); return 0; }
	if(env->is_horse())
		return environment(env);
	else
		return env;
}
object query_horse()
{
	object env=environment();
	if(env->is_horse())
		return env;
	else
		return this_object();
}
string inventory_header() {
    return query_subjective() + //" is carrying:\n";
                                            "���ϴ��ţ�\n";
}

string invis_name() {
    //return "someone";
    return "��������";
}

int is_living() {
  return 1;
}

// This returns an action, so that spells can modify the perspective. i.e:
// You sense: Beek is dead.  Other than that, things are going well for him.

string diagnose() {
    //return "$N $vare in perfect health.\n";
    return "$N��������Ѫ��ӯ����û�����ˡ�\n";
}

/* verb interaction */
mixed direct_cross_obj(object ob) {
    //return "I don't think " + ob->short() + " would appreciate that.\n";
    return "������" + ob->short() + "��������������\n";
}

mixed indirect_give_obj_to_liv(object ob, object liv) {
    return liv->short() + //" politely refuses.\n";
                                          "�����ؾܾ��ˡ�\n";
}

mixed indirect_give_str_to_liv(string str, object liv)
{
	return 1;
}
mixed direct_get_obj(object ob) {
    if (ob == this_body())
    //return "You find your presence uplifting.\n";
      return "���ƺ���������Լ��ٸ��ˡ�\n";
    //return "#I can't do everything.  If you want to pick up another player, try using your social skills.\n";
    return "�Դ��£�����ް취��\n";
}

mixed direct_whisper_liv_str() { return 1; }
mixed direct_whisper_str_to_liv() { return 1; }
mixed direct_whisper_to_liv_str() { return 1; }
string get_base_long()
{
    string res;
    int p_rongmao,p_gender,p_age;
        p_rongmao=this_object()->query_sg_rongmao();
        p_gender=this_object()->query_gender();
        p_age=this_object()->query_age();
    if(!is_visible())
      return "����ǰһƬ��ڣ�ʲôҲ��������\n";
    res=::get_base_long();
    if(res==this_object()->short()+"������ûʲô����ġ�\n")
	res="";
    res=res+this_object()->short() + 
NORMAL_D->get_rongmao( p_age, p_rongmao, p_gender );
    return wrap(res);
}
varargs string inventory_recurse(int depth, mixed avoid) 
{
     return "";
}
string living_desc()
{
	int have_thing=0;
        object env = environment(this_object());
	object obw=this_object()->query_weapon();
	object *obs;
	mixed stat;
	int i;
	string ret_head="";
	string ret="";
	if(env->is_horse()) // ��������
	{
		ret+="����"+env->short()+"��\n";
	}
	if((objectp(obw))&&(obw!=this_object()))
	{
		ret+="�ֳ�"+obw->short()+"��\n";
	}
        foreach (object ob2 in all_inventory(this_object())) 
        {
		
        	stat=ob2-> ob_state() ;
                if(stringp(stat))
		{
			switch(stat)
			{
				case TORSO :
					ret+="��"+ob2->short()+"��\n";
					break;
				case HEAD :
					ret+="ͷ��"+ob2->short()+"��\n";
					break;
				case FEET :
					ret+="��̤"+ob2->short()+"��\n";
					break;
                                case BREST :
                                        ret+="��ǰ����"+ob2->short()+"��\n";
                                        break;

                                case LEGS :
                                       ret+="����"+ob2->short()+"��\n";
                                       break;
                                case HANDS :
					ret+="���ϴ���"+ob2->short()+"��\n";
					break;
                                case ARMORS :
                                       ret+="����һ��"+ob2->short()+"��\n";
                                       break;
                                case ARMS:
                                       ret+="��������"+ob2->short()+"��\n";
                                       break;
			}
	
		}
        }
	if (ret!="")
		ret_head="ֻ��"+short()+"��\n";
	else
	{
		if(random(2))
			ret_head=short()+"����һ˿���ҡ�\n";
		else
			ret_head=short()+"�ƺ��ǳ���¶�塣\n";
	}
	return ret_head+ret;
}
string long()
{
  return get_base_long() + get_extra_long()+NORMAL_D->age_desc(this_object())+living_desc();
}

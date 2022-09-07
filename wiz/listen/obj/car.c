#include <ansi.h>

inherit "/wiz/listen/obj/m_car";
inherit M_VALUE;
//static array horse_act=({});

private int p_level;
void add_hook(string, function);
private function        my_hook;
void horse_heart()
{
	string own;
	call_out("horse_heart",10+random(50));
	own=query_owner();
	if((!find_user(own))&&(!sizeof(get_riders()))){
		tell_environment(this_object(),short()+"�����Զ���ʻģʽ����Զ����ȥ��\n");
		this_object()->remove();
		return;
	}
//	tell_environment(this_object(),short()+horse_act[random(5)]);
}
void set_level(int i)
{
	p_level=i;
}
int query_level()
{
	return p_level;
}
void setup()
{
    if(file_name(previous_object())!=OBJ_D)
    {
        write("�Ƿ�����.\n");
        this_object()->remove();
        return;
    }
    if (!my_hook) {
         my_hook = (: remove_call_out :);
         add_hook("remove", my_hook);
	}
}

int init_obj(string p_id)
{
	mixed par;
	par=OBJ_D->get_obj(p_id);

	set_id(p_id,par["name"]);
	add_id(p_id+" obj");
	set_unit(par["unit"]);

	set_in_room_desc("һ"+par["unit"]+par["name"]+"("+p_id+")\n");

	set_long(par["long"]);

    set_value(par["value"]);

	set_attack_ability(par["att_abi"]);
	set_level(par["level"]); // NPC's default weapon level

    set_relations("on");
    set_preposition("on");

    set_max_capacity(par["size"]*VERY_LARGE);

	set_arrival_msg(par["arr_msg"]);
	set_departure_msg(par["dep_msg"]);

	set_ride_msg(par["up_msg"]);
	set_unride_msg(par["down_msg"]);
	call_out("horse_heart",random(10)+5);
}
int sg_obj() // so it is not a common obj
{
	return 1;
}
string check_obj()
{
	string ret;
	string own;
	object p_id=this_object()->query_primary_id();
	mixed inf;
	inf=OBJ_D->get_obj(p_id);
	ret="��Ʒ���"+sprintf("%-8s  ",OBJ_D->type_name(inf["type"]));
	ret+="�ȼ���"+sprintf("%2d",inf["level"])+"\n��Ǯ��"+
		((inf["value"] < 0) ? ("�޼�֮��"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="��������(���������ɹ���)��+"+sprintf("%2d",inf["att_abi"])+"\n";
	ret+="�ٶȣ�"+100/inf["sp"]+ " ������"+inf["en"]+"\n";
	ret+="�������ģ���"+inf["fe"][0]+" ����"+inf["fe"][1]+"\n";
	ret+="���أ�"+chinese_number(inf["size"])+"�ˡ�\n";

	own=query_owner();
	if(sizeof(own))
	{	own=CHAR_D->get_char(own,"name")+"("+own+")";
		ret+="�����ˣ�"+own+"\n";
	}
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}

mixed is_troop() {
   object env;
   env=environment(this_object());
   if(!objectp(env)) return 0;
   return env->is_troop();
}

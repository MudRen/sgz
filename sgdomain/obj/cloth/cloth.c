#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit "/sgdomain/modules/m_cloth";
inherit M_GETTABLE;
inherit M_VALUE;

private int p_level;
private string owner="";
void set_owner(string s) {
	owner=s;
}
string query_owner() {
	return owner;
}

void set_level(int i)
{	p_level=i;
}
int query_level()
{	return p_level;
}
void setup()
{    if(file_name(previous_object())!=OBJ_D)
    {
        write("�Ƿ�����.\n");
        destruct(this_object());
        return;
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

	set_size(par["size"]);
	set_gettable(1); // food always can get
	set_long(par["long"]);

    set_value(par["value"]);

	set_can_drop(par["can_drop"]);
	set_can_give(par["can_give"]);
	set_can_sell(par["can_sell"]);
	set_is_keeping(par["is_keeping"]);


	set_att_abi(par["att_abi"]);
        set_def_pow(par["def_pow"]);
	set_level(par["level"]); // NPC's default weapon level

    set_slot(par["sub_type"]);
	
    set_wearmsg(par["wear_msg"]);
    set_removemsg(par["rm_msg"]);
}
int sg_obj() // so it is not a common obj
{
	return 1;
}

string check_obj()
{
	string ret;
	string one_name;
	object p_id=this_object()->query_id()[0];
	mixed inf;
	inf=OBJ_D->get_obj(p_id);

	ret="��Ʒ���"+sprintf("%-8s  ",OBJ_D->type_name(inf["type"]))+"�����"+
		OBJ_D->type_name(inf["sub_type"])+"\n";
	ret+="�ȼ���"+sprintf("%2d",inf["level"])+"        ��Ǯ��"+
		((inf["value"] < 0) ? ("�޼�֮��"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="������������(�����ɹ���)��"+sprintf("%2d",inf["att_abi"])+
		"  ��������+"+inf["def_pow"]+"\n";
	ret+="������"+
		((inf["size"]>5) ? (chinese_number(inf["size"]/2)+"�\n")
		: "����\n" );
	one_name=CHAR_D->get_char(owner,"name");
	if(one_name);
		ret+="�����ߣ�"+one_name+"("+owner+")\n";
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}

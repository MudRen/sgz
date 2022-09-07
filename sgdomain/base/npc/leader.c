// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_CHAR;
inherit LIVING;
protected string master;
protected string p_area;
protected string f_id;
protected string master_name;
protected string base_name;
protected int m_busy=0;
int get_busy() {
	return m_busy;
}
void set_busy(int b) {
	m_busy=b;
}
void setup(string a_id,string fd)
{
	object o_h;
	mixed c;
	p_area=a_id;
	f_id=fd;
	o_h=SGBASE(p_area,f_id);
	if(!objectp(o_h)) {
		destruct(this_object());
		return;
	}
	master=o_h->get_leader();
	if(!CHAR_D->char_exist(master)) {
		destruct(this_object());
		return;
	}
	master_name=CHAR_D->get_char(master,"name");
	base_name=BASE_D->get_base(f_id,"name");
	set_name("zong jian","�ܼ�");
	add_id("zong");
	add_id("leader");
	set_gender(1);
    set_proper_name("�ܼ�");

   	set_in_room_desc(base_name+"�ܼ�(zong jian)");
	set_age(40);
	set_sg_rongmao(-1);

	add_ask_str("order","$N��$T�������ܼ���ˡ������һ��ɺð���\n");
	add_question("order","order" );
	
}
string long() {
	return master_name+"�ҵĴ�ܼң���������"+master_name+
		"�������̯�ӣ�����"+base_name+"�ܼࡣ\n";
}
int am_i_ok() {
	object o_h=SGBASE(p_area,f_id);
	if(!objectp(o_h)) return 0;
	if(master==o_h->get_leader()) return 1;
	return 0;
}
void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
	if(!am_i_ok()) {
		this_object()->simple_action(
			"һ�������ܹ�����$N�����ֹ���Щʲô��$N��ɫһ�����֪���ˣ����Ͼ�ȥ��\n");
		this_object()->simple_action("$N�Ҵ�ææ�뿪�ˡ�\n");
		destruct(this_object());
		return;

	}
    switch(matt)
    {
	case "order":
		if(((CHAR_D->get_char(p_id,"area")==p_area)&&
(CHAR_D->get_char(p_id,"ranklocal")>0)&&(CHAR_D->get_char(p_id,"ranklocal")!=1000))
||wizardp(p_id)
||((AREA_D->get_area(p_area,"nation")==CHAR_D->get_char(p_id,"nation"))&&
 (CHAR_D->get_char(p_id,"ranknation")>0)))
		{
			this_object()->targetted_action(
				"$N��æ�������$m$R������ɱС���ˣ�$R�кͷԸ���\n",who);
        new (__DIR__+"farm_menu")->start_menu(who,this_object(),p_area,f_id);
		}
		else {
			this_object()->responda("hehe "+p_id);
		}
		break;
	default:
	}
}
int base_npc() {
	return 1;
}
string get_f_id() {
	return f_id;
}
string get_area() {
	return p_area;
}

#include <mudlib.h>

inherit LIVING;
inherit M_CHAR;

private string nation;
private string who;
private string target;
private int time;
private int busy;

string *dir = ({"n","s","e","w","u","d","o","enter","wu","wd","eu","ed","su","sd","nu","nd","nw","ne","sw","se", });
string *long = ({"north", "south", "east", "west", "up", "down", "out", "enter", "westup", "westdown", "eastup", "eastdown", "southup", "southdown", "northup", "northdown", "northwest", "northeast", "southwest", "southeast"});

string enter_area(object who);
string check_over(object who);
string check_dirs(object who, string arg);
string check_move(object who, string arg);
string get_new_job();
void fail_job(object who);
void succ_job(object who);
int do_award(object who);

void setup()
{
	string *nations, *dest;
	string name;
        object cloth;

        cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
	cloth->move(this_object());
        cloth->do_wear();
    	set_name("xian ren", "����");
    	add_id("xianren");
    	set_gender(1);
	
	nations = COUNTRY_D->list_countries();
	if( !nations || !sizeof(nations) )name = "���˵�";
	else {
		nation = nations[random(sizeof(nations))];
		name = COUNTRY_D->get_country_name(nation)+"��";
	}
	set_proper_name(name+"����");
    	set_in_room_desc(name+"����"+"("+nation+"'s xian ren)");

	foreach(string dd in dir){
		add_question(dd, dd);
		add_ask_str(dd,"$N����һ�룬��$T�����ҿ�Ӧ��"+DIRECTION_D->cdir(DIRECTION_D->abbrdir(dd))+"�ߡ�\n");
	};
	add_question("entry","entry");
	add_ask_str("entry","$N��$T������������Ҫ�Ķ���Ӧ�������棬���Ƚ�ȥ��\n");
	add_question("over", "over");
	add_ask_str("over", "$N����һ�룬��$T�����ҿ�Ӧ���Ѿ����ˡ�\n");

	dest = AREA_D->list_areas();
        foreach(string tt in dest){
                add_question(tt, tt);
                add_ask_str(tt, "$N��$T���������ǵ�" +
                        AREA_D->get_area(tt, "name") +"ȥ�����ɡ�\n");
        };
}
void set_nation(string n)
{
	string name;

	nation = n;
	name = COUNTRY_D->get_country_name(n)+"��";
        set_proper_name(name+"����");
        set_in_room_desc(name+"����"+"("+n+"'s xian ren)");
}
string query_leader()
{
	return who;
}
void set_leader(string name)
{
	if( who && stringp(who) )
		this_object()->simple_action("$N����лл������"+CHAR_D->get_char(who, "name")+"��������Ϊ��ָ·�ء�\n");
	else who = name;
	return;
}
mixed special_answer(object ob, string str)
{
	string id;

	id = ob->query_id()[0];
	if( !who || id != who ){
		this_object()->targetted_action("$N����ֵ��۹������$Tһ�ۣ��Һ�����ʶ�㰡��\n", ob);
		return;
	}
	if( str == "over" ) check_over( ob );
	else if( str == "entry" ) enter_area (ob);
	else if( member_array(str, dir) != -1 ) check_dirs( ob, str );
	else if( member_array(str, AREA_D->list_areas()) != -1) check_move( ob, str );
	else ::special_answer(ob, str);

	return;
}
string enter_area(object who)
{
	string a_id,p_entry;
	a_id=environment(this_object())->get_area();
	p_entry = AREA_D->get_area(a_id, "path")+AREA_D->get_area(a_id,"entry");
	if(!present((a_id+" guard"),environment(this_object()))){
	this_object()->targetted_action("$N���ͷ��ض�$T�����������ڲ����������𣿣�\n",this_body());
	return "";
	}
	else{
	this_object()->responda("ok");
	DELAY_D->delay_simple_action(this_object(),"$N��������ұ��ȥ�ˡ�\n",1);
	this_object()->move(p_entry);
	}
	return "";
}
	
string check_dirs(object who, string arg)
{
	object env;
	mapping exits;
	string final;
	string *msg;

	if( !busy || !intp(busy) ) busy = time();
	if( time() - busy <= 3 ){
		this_object()->targetted_action("$N��$T����һ������Ҫ�����Ұ���\n", who);
		return "";
	}
	busy = time();
	msg = ({"��ҡ��ڵ�", "ҡͷ���Ե�", "���ɲ�����", "����ԥԥ��", });
	env = environment(this_object());
	if( !env )return "Error: report to any wizard online\n";

	exits = env->query_exits();
	exits = filter_array(exits, (: member_array($1, long)!=-1 :));
	if( member_array(DIRECTION_D->abbrdir(arg), keys(exits)) == -1 ){
		this_object()->targetted_action("$N��$T��У��ⷽ�����г�·����\n", who);
		return "";
	};
	if( random(5) == 1 )final = keys(exits)[random(sizeof(exits))];
	else final = DIRECTION_D->abbrdir(arg);

	this_object()->responda("consider");
	this_object()->simple_action("$N"+msg[random(sizeof(msg))]+"��"+DIRECTION_D->cdir(final)+"��ȥ��\n");
	this_object()->move(exits[final]);

	return "";
}
string get_newjob()
{
	string *npc, maker, *goods, final;

	npc = CHAR_D->list_chars();
	npc = filter_array(npc, (: CHAR_D->get_char($1, "is_maker") :));
	maker = npc[random(sizeof(npc))];
	goods = CHAR_D->get_char(maker, "goods");
	if ( !goods||!sizeof(goods) ) return "mantou";
	final = goods[random(sizeof(goods))];
	if( !final || !stringp(final) )return "mantou";
	else return final;
}
void do_consider()
{
	object leader;

	leader = CHAR_D->find_char(who);
	if( !leader || !objectp(leader) ){
		destruct(this_object());
	} else if( !leader->query_link() ){
		fail_job(leader);
	} else if( !target || !stringp(target) || target == ""){
		time = time();
		target = get_newjob();
		leader->set_job("xu zijiang", "memo", OBJ_D->get_obj(target, "name"));
		this_object()->simple_action("$N������˵�м���"+OBJ_D->get_obj(target,"name")+"�Ķ�������֪���������ģ���֪��֪����\n");
	} else {
		if( time + 1200 < time() ) fail_job(leader);
		else this_object()->targetted_action("$N���ͷ�����$T��������û�а���\n",leader);
	}
	return;
}
void fail_job(object who)
{
	string name;

	name = who->query_id()[0];
	this_object()->targetted_action("$N�����Ķ�$T˵�������С�¶��첻�����ߣ�\n", who);
	who->finish_job("xu zijiang");
	CHAR_D->set_char(name, "reputation",
		 CHAR_D->get_char(name, "reputation")-10);
	destruct(this_object());
	return;
}
void succ_job(object who)
{
	string name;

	who->finish_job("xu zijiang");

	name = who->query_id()[0];

	this_object()->simple_action("$N����һ"+OBJ_D->get_obj(target,"unit")+OBJ_D->get_obj(target, "name")+"������������ϸ�Ķ����š�\n");
	this_object()->targetted_action("$N���˵Ķ�$T˵��̫лл���ˣ��Ժ���ʲôҪ��æ�ľ��ܽ���\n", who);

	ROBOT->robot_test(who, (: do_award :) );
}
int do_award(object who)
{
	int rep, gold, point;
	string name, *sks, skill;

	name = who->query_id()[0];
	rep  = 100+random(50);
	gold = 20000+random(10000);
	sks  = keys(who->get_sg_skills());

	if( who->query_robot() ){
		write("��Ǹ������Ĵ𰸣�û���κν������´���Ŭ���ɣ�\n");
		destruct(this_object());
		return 2;
	};
	CHAR_D->set_char(name, "reputation",
		CHAR_D->get_char(name, "reputation")+rep);
	CHAR_D->set_char_loyalty(name, nation,
		CHAR_D->get_char_loyalty(name, nation)+1);
	who->set_all_con_money(who->query_all_con_money()+gold);

	this_object()->targetted_action("$N��$T˵��������ڣ�\n", who);
	who->finish_job("xu zijiang");
	write("�㱻�����˼����ƽ�\n");
	write("�����������ˡ�\n");
	write("����"+COUNTRY_D->get_country(nation,"name")+"���Ѻö�����ˡ�\n");
	if( !sks||!arrayp(sks)||!sizeof(sks) )
	{
	destruct(this_object());
	 return 1;
	}
        sks = filter_array(sks, (: SG_SKILL_D->query_type($1)==4 :));
        if( !sks||!arrayp(sks)||!sizeof(sks) )
	{
	destruct(this_object());
	 return 1;
	}
        skill = sks[random(sizeof(sks))];
        point = who->query_job("xu zijiang", "count");
        if( point>200 ) point = 200;
        point = point + 50 + random(50);
        who->award_exp(point ,skill);
        write("���%^H_CYAN%^"+SG_SKILL_D->query_name(skill)+"%^RESET%^��
		����"+chinese_number(point)+"�㣡\n");
	destruct(this_object());
        return 1;	
}
string check_over(object who)
{
	string name, goods;
	object env, *ins;
	
	if(!who->query_job("xu zijiang","beg_time")) {
		this_object()->targetted_action("$N��$T���ͷ��ص���֪���ˣ�֪���ˡ�\n",who);
		return ;
	}

	env = environment(this_object());
	ins = all_inventory(env);
	foreach(object oo in ins){
		name = oo->query_id()[0];
		goods = CHAR_D->get_char(name, "goods");
		if( goods && arrayp(goods) && sizeof(goods) ){
			if( member_array(target, goods) != -1 ){
				succ_job( who );
				return "";
			}
		}
	}
	this_object()->targetted_action("$N����$Tһ�ۣ���˵�˵���\n",who);
	return "";
}
string check_move(object who, string arg)
{
	string where;
	object room, room2, here, mafu;

	here = environment(this_object());
	if( !mafu = present("ma fu", here) ){
		this_object()->simple_action("$N̾�˿�����������Ķ���\n");
		return "";
	}
	if( who->query_all_con_money()<500 ){
		this_object()->simple_action("$N̾�˿�����û��Ǯ���Ķ�Ҳȥ���ɡ�\n");
		return "";
	}
	who->set_all_con_money(who->query_all_con_money()-500);
	where = AREA_D->get_area(arg, "path")+AREA_D->get_area(arg, "go");
	room  = load_object(where);
	where = AREA_D->get_area(arg, "path")+AREA_D->get_area(arg,"entry");
	room2 = load_object(where);
	if( !room || !objectp(room) || !room2 || !objectp(room2) )
		this_object()->simple_action("$N̾�˿������Ƕ���ͨ���㡣\n");
	else {
		this_object()->targetted_action("$N��$T��ͷ�����ã��߰ɣ�\n", who);
		this_object()->move(room2);
		who->move(room);
		tell_from_outside(room, who->query_id()[1]+"��"+this_object()->query_in_room_desc()+"�糾���͵ĸϵ��ˡ�\n");
	}
	return "";
}
int query_clean_up() { // so will not auto dissappear
        return 1;
}

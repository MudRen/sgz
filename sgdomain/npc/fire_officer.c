//fire officer for fireman job
//flee@sgz
#include <mudlib.h>
#include <daemons.h>
#include <sanguo.h>

#define EXTI "/wiz/flee/job/extinguisher.c"
#define FIRE "/wiz/flee/job/fire.c"
#define CITY_MAP "/sgdomain/area/cities/changan/"

inherit LIVING;
inherit "/sgdomain/modules/m_charanswer.c";

object room;
object fire;
int num_tool;
int is_fire;

int ask_tool(object player);
int ask_job(object player);
int ask_jbhj(object player);

void setup()
{
	set_name("officer", "��Ա");
	set_in_room_desc("һλ��ɷ���Ĺ�Ա(officer)");
	set_long("һλ��ɷ���Ĺ�Ա(officer)");
	set_gender(1);
	add_question("extinguisher", "");
	add_question("ˮ��", "");
	add_question("job", "");
	add_question("���", "");		
	add_question("jbhj", "");
	num_tool = 4;
	is_fire = 0;
}
mixed special_answer(object ob, string str)
{
	object player;
	player = this_body();

	if( !str || !stringp(str) )return ::special_answer(ob, str);
	if( str == "extinguisher" || str == "ˮ��" )
		ask_tool( player );
	else if( str == "job" || str == "���")
		ask_job( player );
	else if( str == "jbhj" )
		ask_jbhj( player );
	else return ::special_answer(ob, str);
}
int add_tool()
{
	num_tool++;
}
int set_fire()
{
	is_fire = 0;
}
int ask_tool(object player)
{
	object extinguisher;

	if( num_tool <= 0 ){
		this_object()->simple_action("$Nҡͷ����ˮ�������������ˣ���Ȼ�������\n");
		return 1;
	};
	num_tool--;
	call_out("add_tool", 900);
	extinguisher = new( EXTI );
	this_object()->targetted_action("$N֣�صİѽ�һ��ˮ����$T��\n", player);
	extinguisher->move( player );
	return 1;	
}
int ask_job(object player)
{
	object tool;
	string *file_name;
	string room_name;

	if( !tool = present("extinguisher", player) ){
		this_object()->simple_action("$NЦ����лл���ģ����ǻᰲ�ŵġ�\n");
		return 1;
	};
	if( is_fire == 1 ){
		if( !room || !objectp( room ) ){
			call_out("set_fire", 100);
			this_object()->simple_action("$N˵��������һ�а��ã�û��ʲô�𻼡�\n");
			return 1;
		} else {
			this_object()->simple_action("$N�鿴��һ�£����ŵ�ͼָ��ָ����������л��֣���ȥ��\n");
			printf("\n%s\n", room->get_brief());
	 		printf("\n%s\n", room->long());
			is_fire = 1;
			return 1;
		};
	} else {
		file_name = get_dir( CITY_MAP );
		room_name = file_name[random(sizeof(file_name))];		
		room_name = CITY_MAP + room_name;
		if( !file_size(room_name) || !room = load_object( room_name )
			|| room_name == "warroom.c" ){
			this_object()->simple_action("$N̾��һ��������û���ֻ�Դ���Ķ���\n");
			return 1;
		};
		fire = new( FIRE );
		fire->move( room );
		fire->set("owner", this_object());
		this_object()->simple_action("$N�鿴��һ�£����ŵ�ͼָ��ָ����������л��֣���ȥ��\n");
		is_fire = 1;
		printf("\n%s\n", room->get_brief());
		printf("\n%s\n", room->long());
		return 1;
	}
	return 1;
}
int ask_jbhj(object player)
{
	"/sgdomain/event/ev_learnskills.c"->learn_skill(player, "jbhj");
	return 1;
}

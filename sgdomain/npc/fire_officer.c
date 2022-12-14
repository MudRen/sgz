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
	set_name("officer", "官员");
	set_in_room_desc("一位神采飞扬的官员(officer)");
	set_long("一位神采飞扬的官员(officer)");
	set_gender(1);
	add_question("extinguisher", "");
	add_question("水龙", "");
	add_question("job", "");
	add_question("灭火", "");		
	add_question("jbhj", "");
	num_tool = 4;
	is_fire = 0;
}
mixed special_answer(object ob, string str)
{
	object player;
	player = this_body();

	if( !str || !stringp(str) )return ::special_answer(ob, str);
	if( str == "extinguisher" || str == "水龙" )
		ask_tool( player );
	else if( str == "job" || str == "灭火")
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
		this_object()->simple_action("$N摇头道：水龙都被人拿完了，请等会再来。\n");
		return 1;
	};
	num_tool--;
	call_out("add_tool", 900);
	extinguisher = new( EXTI );
	this_object()->targetted_action("$N郑重的把交一条水龙给$T。\n", player);
	extinguisher->move( player );
	return 1;	
}
int ask_job(object player)
{
	object tool;
	string *file_name;
	string room_name;

	if( !tool = present("extinguisher", player) ){
		this_object()->simple_action("$N笑道：谢谢关心，我们会安排的。\n");
		return 1;
	};
	if( is_fire == 1 ){
		if( !room || !objectp( room ) ){
			call_out("set_fire", 100);
			this_object()->simple_action("$N说道：现在一切安好，没有什么火患。\n");
			return 1;
		} else {
			this_object()->simple_action("$N查看了一下，对着地图指了指，这儿可能有火灾，快去。\n");
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
			this_object()->simple_action("$N叹了一口气：还没发现火源在哪儿。\n");
			return 1;
		};
		fire = new( FIRE );
		fire->move( room );
		fire->set("owner", this_object());
		this_object()->simple_action("$N查看了一下，对着地图指了指，这儿可能有火灾，快去。\n");
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

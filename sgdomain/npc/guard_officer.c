//guard officer for guard door job
//flee@sgz
#include <mudlib.h>
#include <daemons.h>
#include <sanguo.h>
#define __CITY__DIR__ "/sgdomain/area/cities/changan/"
#define GUARD_P ({"ca_xcm.c", "ca_dcm.c", "ca_bcm.c", "ca_ncm.c", })
		
inherit LIVING;
inherit "/sgdomain/modules/m_charanswer.c";

mapping guard;
int ask_guard(object player);
void do_check_guard();

void setup()
{
	int i;
	set_name("officer", "官员");
	set_in_room_desc("一位神采飞扬的官员(officer)");
	set_long("一位神采飞扬的官员(officer)");
	set_gender(1);
	add_question("job", "job");
	add_question("guard", "guard");
	add_question("守卫", "守卫");
	guard = ([ ]);
	for( i = 0; i < sizeof(GUARD_P); i++)
		guard[GUARD_P[i]] = "";
	call_out("do_check_guard", 15);
}
mixed special_answer(object ob, string str)
{
	object player;
	player = this_body();

	if( !str || !stringp(str) )return ::special_answer(ob, str);
	if( str == "守卫" || str == "job" || str == "guard" )
		ask_guard( player );
	else return ::special_answer(ob, str);
}
int ask_guard(object player)
{
	int i;
	string *rooms;	
	object room;
	object guarder;

	rooms = keys( guard );
	for( i = 0; i < sizeof(rooms); i++){
		room = load_object( __CITY__DIR__ + rooms[i] );
		if( !guarder = find_body( guard[rooms[i]] ) ){
			printf("%s点了点头。\n", this_object()->query_name());
			printf("%s对着%s说道：%s正少个人，快去吧。\n",
				this_object()->query_name(), player->query_name(),
				room->short());
			guard[rooms[i]] = player->query_id()[0];
			player->set("guard_time", time());
			return 1;
		};
	};
	this_object()->simple_action("官员笑道：我们人手已经够了，请稍等再来吧。\n");	
	return 1;
}
void do_check_guard(){
	int i, j, skill, exp;
	string *rooms;
	object guarder;

	rooms = keys(guard);
	for( i = 0; i < sizeof(rooms); i++ ){
		guarder	= find_body( guard[rooms[i]] );
		if( !guarder )continue;
		if( time() - guarder->query("guard_time") >= 300){
			guard[rooms[i]] = "";
			tell( guarder, "时间差不多了，你可以去休息休息了。\n");
			continue;
		};
		if( base_name( environment( guarder ) ) + ".c"
			!= __CITY__DIR__ + rooms[i]){
			tell( guarder, "干吗哪，快去你该去的地方。\n");	
			continue;
		} else {
			guarder->simple_action("$N全神贯注的盯着每一个过往的行人。 \n");
			skill = guarder->query_sk_level("sk_zhimou");
		        exp = guarder->query_sk_exp("sk_zhimou");
			if( skill < 41 ) guarder->set_sg_skill("sk_zhimou", skill, 
				exp + random(10) + 10 );
		};
	};			
	remove_call_out("do_check_guard");
	call_out("do_check_guard", 15);
}



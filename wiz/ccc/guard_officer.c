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
	set_name("officer", "��Ա");
	set_in_room_desc("һλ��ɷ���Ĺ�Ա(officer)");
	set_long("һλ��ɷ���Ĺ�Ա(officer)");
	set_gender(1);
	add_question("job", "job");
	add_question("guard", "guard");
	add_question("����", "����");
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
	if( str == "����" || str == "job" || str == "guard" )
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
			printf("%s���˵�ͷ��\n", this_object()->query_name());
			printf("%s����%s˵����%s���ٸ��ˣ���ȥ�ɡ�\n",
				this_object()->query_name(), player->query_name(),
				room->short());
			guard[rooms[i]] = player->query_id()[0];
			player->set("guard_time", time());
			return 1;
		};
	};
	this_object()->simple_action("��ԱЦ�������������Ѿ����ˣ����Ե������ɡ�\n");	
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
			tell( guarder, "ʱ�����ˣ������ȥ��Ϣ��Ϣ�ˡ�\n");
			continue;
		};
		if( base_name( environment( guarder ) ) + ".c"
			!= __CITY__DIR__ + rooms[i]){
			tell( guarder, "�����ģ���ȥ���ȥ�ĵط���\n");	
			continue;
		} else {
			guarder->simple_action("$Nȫ���ע�Ķ���ÿһ�����������ˡ� \n");
			skill = guarder->query_sk_level("sk_zhimou");
		        exp = guarder->query_sk_exp("sk_zhimou");
			if( skill < 41 ) guarder->set_sg_skill("sk_zhimou", skill, 
				exp + random(10) + 10 );
		};
	};			
	remove_call_out("do_check_guard");
	call_out("do_check_guard", 15);
}



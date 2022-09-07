#include <mudlib.h>
#include <ansi.h>
#define MSG_ROOM load_object(__DIR__"join_room.c")

inherit OUTDOOR_ROOM;

varargs void receive_inside_msg(string msg, object * exclude, int message_type,mixed other)
{
	msg = HIY+"〖赛场中〗"+NOR+msg;
	tell_from_inside(MSG_ROOM, msg, 0);
}
void setup(){
        set_light(50);
        set_brief(""+YEL+"比武大会赛场"+NOR+"");
	set_long("这儿就是天下英雄争夺霸主的地方。");
       set("no_fight", 0);
}

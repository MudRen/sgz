#include <mudlib.h>
#include <ansi.h>
#define MSG_ROOM load_object(__DIR__"join_room.c")

inherit OUTDOOR_ROOM;

varargs void receive_inside_msg(string msg, object * exclude, int message_type,mixed other)
{
	msg = HIY+"�������С�"+NOR+msg;
	tell_from_inside(MSG_ROOM, msg, 0);
}
void setup(){
        set_light(50);
        set_brief(""+YEL+"����������"+NOR+"");
	set_long("�����������Ӣ����������ĵط���");
       set("no_fight", 0);
}

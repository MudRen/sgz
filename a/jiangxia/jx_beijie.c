// this room is created by buzzer.c
// driver is �������
// created date is Sat Jul 23 22:03:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jiangxia/jx_xiaochang.c",

"east":"/a/jiangxia/jx_fanguan.c",

"north":"/a/jiangxia/jx_dukou.c",

"west":"/a/jiangxia/jx_chaguan.c",
 ]));
}

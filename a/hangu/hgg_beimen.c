// this room is created by buzzer.c
// driver is �������
// created date is Tue Jun 14 22:15:03 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hangu");
set_light(50);
set_brief("%^YELLOW%^"+"���ȹر���"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hangu/hgg_dalu1.c",

"west":"/a/hangu/hgg_dalu.c",

"east":"/a/hangu/hgg_laofang.c",

"south":"/a/hangu/hgg_yingzhai.c",
 ]));
}

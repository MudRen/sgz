// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 19:01:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"¶«´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/nanpi/np_dalu.c",

"west":"/a/nanpi/np_fenghuangtai.c",

"east":"/a/nanpi/np_dongchengmen.c",

"south":"/a/nanpi/np_bingying.c",
 ]));
}

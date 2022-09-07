// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sun Jun 12 21:41:08 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"ÓªÕ¯"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/bowangpo/bwp_zhalan.c",

"south":"/a/bowangpo/bwp_laofang.c",

"west":"/a/bowangpo/bwp_xiaodao.c",
 ]));
}

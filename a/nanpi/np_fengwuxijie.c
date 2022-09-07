// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 19:26:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"·ïÎèÎ÷½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/nanpi/np_xinyueqiao.c",

"west":"/a/nanpi/np_guanzhai.c",

"east":"/a/nanpi/np_beidajie.c",
 ]));
}

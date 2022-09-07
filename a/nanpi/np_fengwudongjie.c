// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 19:23:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"·ïÎè¶«½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/nanpi/np_beidajie.c",

"east":"/a/nanpi/np_buzhuang.c",

"south":"/a/nanpi/np_huashi.c",
 ]));
}

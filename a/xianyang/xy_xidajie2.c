// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:34:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xianyang/xy_xichengmen.c",

"south":"/a/xianyang/xy_tanmaying.c",

"east":"/a/xianyang/xy_xidajie.c",
 ]));
}

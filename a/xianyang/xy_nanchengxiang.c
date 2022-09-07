// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:44:04 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÄÏ³ÇÏï"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xianyang/xy_nanchengxiang2.c",

"east":"/a/xianyang/xy_nanchengxiang1.c",

"north":"/a/xianyang/xy_nandajie.c",
 ]));
}

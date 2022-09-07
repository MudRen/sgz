// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:25:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"´º»ªÂ¥"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xianyang/xy_dongdajie2.c",
 ]));
}

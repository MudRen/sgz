// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:48:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"Ç®×¯"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xianyang/xy_nanchengxiang1.c",
 ]));
}

// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:35:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"Ì½ÂíÓª"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xianyang/xy_xidajie2.c",
 ]));
}

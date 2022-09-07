// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Fri May 27 19:05:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"¾üÓª"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/jingyang/jy_yishiting.c",

"south":"/a/jingyang/jy_chengdongjie.c",
 ]));
}

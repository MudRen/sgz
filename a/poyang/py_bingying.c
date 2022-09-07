// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu Jun  2 21:04:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"±øÓª"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/poyang/py_zahuopu.c",

"west":"/a/poyang/py_yishiting.c",

"south":"/a/poyang/py_lianbingchang.c",
 ]));
}

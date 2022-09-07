// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu Jun  2 20:58:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/poyang/py_kezhan.c",

"west":"/a/poyang/py_xichengmen.c",

"east":"/a/poyang/py_naoshi.c",
 ]));
}

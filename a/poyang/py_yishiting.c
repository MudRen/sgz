// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu Jun  2 21:05:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÒéÊÂÌü"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/poyang/py_bingying.c",
 ]));
}

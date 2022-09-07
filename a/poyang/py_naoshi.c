// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Thu Jun  2 20:57:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"ƒ÷ –"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/poyang/py_lianbingchang.c",

"east":"/a/poyang/py_yamen.c",

"west":"/a/poyang/py_xijie.c",

"south":"/a/poyang/py_nanjie.c",
 ]));
}

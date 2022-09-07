// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Thu Jun  2 20:56:02 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"πŸ’¨"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/poyang/py_xiaoxiang.c",
 ]));
}

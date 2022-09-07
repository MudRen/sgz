// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 19:25:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"±±¥ÛΩ÷"+"%^RESET%^");
set_long("");
set_exits( ([
"southeast":"/a/nanpi/np_jianyu.c",

"southwest":"/a/nanpi/np_yamen.c",

"west":"/a/nanpi/np_fengwuxijie.c",

"north":"/a/nanpi/np_beichengmen.c",

"east":"/a/nanpi/np_fengwudongjie.c",
 ]));
}

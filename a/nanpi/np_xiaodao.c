// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 19:33:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"–°µ¿"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/nanpi/np_daxitai.c",

"east":"/a/nanpi/np_dalu.c",
 ]));
}

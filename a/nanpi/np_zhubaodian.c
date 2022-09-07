// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 19:06:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"÷È±¶µÍ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/nanpi/np_xiaochang.c",
 ]));
}

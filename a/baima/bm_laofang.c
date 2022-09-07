// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Thu Jun  2 21:17:08 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("baima");
set_light(50);
set_brief("%^YELLOW%^"+"¿Œ∑ø"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/baima/bm_tulu.c",
 ]));
}

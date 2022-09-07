// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun Jun 12 20:19:50 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bailangshan");
set_light(50);
set_brief("%^YELLOW%^"+"¿Œ∑ø"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/bailangshan/bls_junying.c",
 ]));
}

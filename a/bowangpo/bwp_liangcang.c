// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun Jun 12 21:43:52 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"¡∏≤÷"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/bowangpo/bwp_zhalan.c",
 ]));
}

// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 20:05:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"√Ò∑ø"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/daixian/dx_xijie.c",
 ]));
}

// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sat May 28 11:42:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"≤÷ø‚"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xianyang/xy_machang.c",
 ]));
}

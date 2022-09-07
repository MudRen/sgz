// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sat May 28 19:34:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"ÀÈ Ø¬∑"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuling/wl_suishilu3.c",

"south":"/a/wuling/wl_nanmen.c",

"west":"/a/wuling/wl_suishilu1.c",
 ]));
}

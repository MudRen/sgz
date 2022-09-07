// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sat May 28 19:29:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"–°œÔ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/wuling/wl_suishilu1.c",

"east":"/a/wuling/wl_jiuguan.c",

"west":"/a/wuling/wl_chaguan.c",

"north":"/a/wuling/wl_dadao2.c",
 ]));
}

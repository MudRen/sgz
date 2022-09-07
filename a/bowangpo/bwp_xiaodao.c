// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun Jun 12 21:38:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"–°µ¿"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/bowangpo/bwp_yingzhai.c",

"west":"/a/bowangpo/bwp_yangchangxiaodao.c",

"north":"/a/bowangpo/tmp.c",
 ]));
}

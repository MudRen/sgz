// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 15:57:56 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"Ð£³¡"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/shangdang/sd_machang.c",
"west":"/a/shangdang/sd_nandajie1.c",
"north":"/a/shangdang/tmp.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 15:58:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"Âí³¡"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/shangdang/sd_nandajie2.c",

"north":"/a/shangdang/sd_xiaochang.c",
 ]));
}

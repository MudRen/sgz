// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 16:35:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"Á¸²Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/shangdang/sd_jvhuisuo.c",

"west":"/a/shangdang/sd_beidajie.c",
 ]));
}

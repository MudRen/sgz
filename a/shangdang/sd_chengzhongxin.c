// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:32:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/shangdang/sd_beidajie.c",

"south":"/a/shangdang/sd_nandajie1.c",
"west":"/a/shangdang/sd_xidajie.c",
"east":"/a/shangdang/sd_dongdajie.c",
 ]));
}

// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:44:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/shangdang/sd_xidajie.c",

"north":"/a/shangdang/sd_yishiting.c",

"east":"/a/shangdang/sd_beidajie.c",
 ]));
}

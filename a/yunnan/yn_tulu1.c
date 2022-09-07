// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jun  3 22:06:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"ÍÁÂ·1"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/yunnan/yn_tulu2.c",

"east":"/a/yunnan/yn_huadian.c",

"west":"/a/yunnan/yn_jinpu.c",

"south":"/a/yunnan/yn_chengzhongxin.c",
 ]));
}

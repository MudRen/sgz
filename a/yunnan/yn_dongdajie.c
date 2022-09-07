// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jun  3 22:04:09 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"¶«´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/yunnan/yn_jiuguan.c",

"north":"/a/yunnan/yn_guanzhai.c",

"west":"/a/yunnan/yn_chengzhongxin.c",
 ]));
}

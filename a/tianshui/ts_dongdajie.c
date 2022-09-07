// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May  8 21:11:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"¶«´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/tianshui/ts_chengzhongxin.c",

"east":"/a/tianshui/ts_dongchengmen.c",

"south":"/a/tianshui/tmp.c",

"north":"/a/tianshui/ts_guanzhai.c",
 ]));
}

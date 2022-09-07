// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu May 26 20:08:52 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"²¼×¯"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/taiyuan/ty_xidajie1.c",
 ]));
}

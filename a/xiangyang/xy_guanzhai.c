// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu Jul 28 19:09:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"¹ÙÕ¬"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xiangyang/xy_nandajie2.c",
 ]));
}

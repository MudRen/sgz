// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jul 29 11:06:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÈâÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xiangyang/xy_huadian.c",

"north":"/a/xiangyang/xy_tuzhaichang.c",
 ]));
}

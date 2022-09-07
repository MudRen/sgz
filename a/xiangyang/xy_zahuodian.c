// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jul 29 10:36:50 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÔÓ»õµê"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xiangyang/xy_guopu.c",

"west":"/a/xiangyang/xy_caishichang.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jul 29 10:49:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"´òÌúÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xiangyang/xy_tianchijie4.c",
 ]));
}

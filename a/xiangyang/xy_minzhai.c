// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jul 29 10:33:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÃñÕ¬"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xiangyang/xy_tianchijie2.c",
 ]));
}

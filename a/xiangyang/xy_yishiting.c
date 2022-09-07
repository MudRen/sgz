// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu Jul 28 19:10:11 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÒéÊÂÌü"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xiangyang/xy_junying.c",
 ]));
}

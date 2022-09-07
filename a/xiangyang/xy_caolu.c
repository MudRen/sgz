// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jul 29 11:08:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"²ÝÂ®"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xiangyang/xy_qingzhuxiaojing.c",
 ]));
}

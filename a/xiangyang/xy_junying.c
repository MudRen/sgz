// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu Jul 28 19:09:51 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"¾üÓª"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xiangyang/xy_yishiting.c",

"west":"/a/xiangyang/xy_nandajie2.c",
 ]));
}

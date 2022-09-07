// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat Jul 23 22:08:29 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"±øÓª"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jiangxia/jx_yishiting.c",

"west":"/a/jiangxia/jx_xiaochang.c",
 ]));
}

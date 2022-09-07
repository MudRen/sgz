// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat Jul 23 22:15:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/jiangxia/jx_xichengmen.c",

"east":"/a/jiangxia/jx_guangchang.c",
 ]));
}

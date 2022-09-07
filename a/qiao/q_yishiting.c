// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May 29 20:48:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"ÒéÊÂÌü"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/qiao/q_xiaochang.c",
 ]));
}

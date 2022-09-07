// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May 29 20:50:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"ºóÔº"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/qiao/q_guanzhai.c",
 ]));
}

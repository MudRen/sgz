// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May  8 21:17:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"ÒéÊÂÌü"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/tianshui/ts_junying.c",
 ]));
}

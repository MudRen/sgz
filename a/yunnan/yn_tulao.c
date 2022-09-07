// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jun  3 22:01:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"ÍÁÀÎ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/yunnan/yn_xidajie.c",
 ]));
}

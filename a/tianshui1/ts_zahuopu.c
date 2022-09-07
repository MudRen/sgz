// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May  8 21:16:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"ÔÓ»õÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/tianshui/ts_xidajie.c",
 ]));
}

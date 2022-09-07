// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May 31 08:59:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"Ìú½³ÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/nanpi/np_bingying.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jun  3 22:11:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"ÔÓ»õÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yunnan/yn_tulu2.c",
 ]));
}

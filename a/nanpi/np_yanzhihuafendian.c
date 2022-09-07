// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May 31 08:57:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"ëÙÖ¬»¨·Ûµê"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/nanpi/np_nandajie.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May 31 09:09:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"¼àÓü"+"%^RESET%^");
set_long("");
set_exits( ([
"northwest":"/a/nanpi/np_beidajie.c",
 ]));
}

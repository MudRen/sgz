// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue Jul 19 09:46:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changbanpo");
set_light(50);
set_brief("%^YELLOW%^"+"¶Ï±Ú²ÐÔ«"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changbanpo/cbp_kujin.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun Jul 17 23:17:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"Ã©ÎÝ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/gongan/ga_chucangshi.c",

"south":"/a/gongan/ga_tulu.c",
 ]));
}

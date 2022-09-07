// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri May  6 21:56:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"µÀ¿Ú"+"%^RESET%^");
set_long("");
set_exits( ([
"southeast":"/a/wuguan/wg_huangtulu.c",
 ]));
}

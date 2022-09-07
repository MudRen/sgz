// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri May  6 21:55:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"ÀÎ·¿"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuguan/wg_huangtulu.c",
 ]));
}

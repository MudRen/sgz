// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri May  6 15:18:05 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"ºÓ±ß"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuzhangyuan/wzy_xiaolu.c",
 ]));
}

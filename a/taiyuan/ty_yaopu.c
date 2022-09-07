// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu May 26 19:50:04 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Ò©ÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/taiyuan/ty_dongdajie2.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 20:04:12 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"³ÉÒÂÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hongnong/hn_nandajie1.c",
 ]));
}

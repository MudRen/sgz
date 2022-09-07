// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 20:04:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"ÑÃÃÅ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/hongnong/hn_laofang.c",

"east":"/a/hongnong/hn_nandajie1.c",
 ]));
}

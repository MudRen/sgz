// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 20:17:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"±±´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/hongnong/hn_liangcang.c",

"north":"/a/hongnong/hn_machang.c",

"west":"/a/hongnong/hn_junying.c",

"south":"/a/hongnong/hn_chengzhongxin.c",
 ]));
}

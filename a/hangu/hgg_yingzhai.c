// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue Jun 14 22:12:47 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("hangu");
set_light(50);
set_brief("%^YELLOW%^"+"ÓªÕ¯"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hangu/hgg_beimen.c",

"south":"/a/hangu/hgg_nanmen.c",

"west":"/a/hangu/hgg_zhongjunzhang.c",

"southwest":"/a/hangu/tmp.c",
 ]));
}

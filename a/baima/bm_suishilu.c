// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu Jun  2 21:22:54 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("baima");
set_light(50);
set_brief("%^YELLOW%^"+"ËéÊ¯Â·"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/baima/bm_nandaokou.c",

"north":"/a/baima/bm_xiaochang.c",
 ]));
}

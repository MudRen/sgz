// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu Jun  2 21:26:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("baima");
set_light(50);
set_brief("%^YELLOW%^"+"ÓªÕ¯"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/baima/bm_beidaokou.c",

"east":"/a/baima/bm_shuaizhang.c",

"south":"/a/baima/bm_xiaochang.c",
 ]));
}

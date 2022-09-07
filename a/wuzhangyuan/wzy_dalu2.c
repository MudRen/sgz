// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri May  6 15:07:55 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"´óÂ·"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/wuzhangyuan/wzy_yingzhai.c",

"south":"/a/wuzhangyuan/wzy_laofang.c",

"north":"/a/wuzhangyuan/wzy_yingfang.c",

"east":"/a/wuzhangyuan/wzy_dalu1.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu May 26 19:46:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"¶«´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/taiyuan/ty_dongdajie1.c",

"south":"/a/taiyuan/ty_yaopu.c",

"east":"/a/taiyuan/ty_dongchengmen.c",

"north":"/a/taiyuan/tmp.c",
 ]));
}

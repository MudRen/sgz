// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 21:02:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"±±½Ö¶«"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/chaisang/cs_yamen.c",

"east":"/a/chaisang/cs_machang.c",

"north":"/a/chaisang/cs_junying.c",

"west":"/a/chaisang/cs_beijiezhong.c",
 ]));
}

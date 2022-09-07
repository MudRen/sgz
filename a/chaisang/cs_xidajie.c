// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 20:58:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chaisang/cs_yaopu.c",

"west":"/a/chaisang/cs_xichengmen.c",

"east":"/a/chaisang/cs_xiaoshiqiao.c",
 ]));
}

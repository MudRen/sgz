// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu May 26 20:44:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/taiyuan/ty_xichengmen.c",

"north":"/a/taiyuan/ty_yamen.c",

"south":"/a/taiyuan/ty_machang.c",

"east":"/a/taiyuan/ty_xidajie1.c",
 ]));
}

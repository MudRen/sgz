// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 20:51:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"ÄÏ½Ö¶«"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/chaisang/cs_kezhan.c",

"east":"/a/chaisang/cs_datiepu.c",

"west":"/a/chaisang/cs_dajishi.c",
 ]));
}

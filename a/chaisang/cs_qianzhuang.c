// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 21:01:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"Ç®×¯"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/chaisang/cs_beijiexi.c",
 ]));
}

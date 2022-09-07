// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 19:24:37 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"²¼×¯"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/nanpi/np_fengwudongjie.c",
 ]));
}

// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 19:28:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"ĞÂÔÂÇÅ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/nanpi/np_xiaolu.c",

"west":"/a/nanpi/np_fengyuting.c",

"north":"/a/nanpi/np_fengwuxijie.c",
 ]));
}

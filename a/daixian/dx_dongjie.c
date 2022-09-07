// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 20:07:07 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"¶«½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/daixian/dx_dongchengmen.c",

"west":"/a/daixian/dx_guangchang.c",
 ]));
}

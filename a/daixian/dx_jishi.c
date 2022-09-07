// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 20:08:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"ºØ –"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/daixian/dx_beijie.c",

"east":"/a/daixian/dx_kezhan.c",

"south":"/a/daixian/dx_guangchang.c",
 ]));
}

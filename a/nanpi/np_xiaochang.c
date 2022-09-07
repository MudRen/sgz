// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 19:06:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"–£≥°"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/nanpi/np_lianhuachi.c",

"east":"/a/nanpi/np_liangcang.c",

"west":"/a/nanpi/np_zhubaodian.c",

"north":"/a/nanpi/np_xidajie.c",
 ]));
}

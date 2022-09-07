// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 19:22:05 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"ª® –"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/nanpi/np_fengwudongjie.c",

"east":"/a/nanpi/np_qianzhuang.c",

"south":"/a/nanpi/np_dalu.c",
 ]));
}

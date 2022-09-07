// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 20:57:47 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"–° Ø«≈"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chaisang/cs_beijiexi.c",

"west":"/a/chaisang/cs_xidajie.c",

"south":"/a/chaisang/cs_nanjiexi.c",
 ]));
}

// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 21:08:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"—√√≈"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chaisang/cs_jianyu.c",

"north":"/a/chaisang/cs_beijiedong.c",
 ]));
}

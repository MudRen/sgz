// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 20:56:09 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"‘”ªıµÍ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/chaisang/cs_chengyidian.c",

"north":"/a/chaisang/cs_nanjiexi.c",
 ]));
}

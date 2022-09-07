// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 21:01:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"±±Ω÷÷–"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/chaisang/cs_zhubaodian.c",

"east":"/a/chaisang/cs_beijiedong.c",

"west":"/a/chaisang/cs_beijiexi.c",
 ]));
}

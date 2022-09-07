// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 17:12:04 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"≤À –ø⁄"+"%^RESET%^");
set_long("");
set_exits( ([

"northwest":"/a/qiao/q_shigongqiao.c",

"northeast":"/a/qiao/q_changting.c",

"east":"/a/qiao/q_laoyu.c",

"west":"/a/qiao/q_xianyamen.c",

"south":"/a/qiao/q_jishi.c",
 ]));
}

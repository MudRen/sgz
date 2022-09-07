// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun Jun 12 20:14:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bailangshan");
set_light(50);
set_brief("%^YELLOW%^"+"–£≥°"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/bailangshan/bls_yingzhai.c",

"north":"/a/bailangshan/bls_shanlu.c",

"east":"/a/bailangshan/bls_zhalan.c",

"south":"/a/bailangshan/tmp.c",
 ]));
}

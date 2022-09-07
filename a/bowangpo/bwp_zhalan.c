// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun Jun 12 21:42:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"’§¿∏"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/bowangpo/bwp_daokou.c",

"south":"/a/bowangpo/bwp_liangcang.c",

"north":"/a/bowangpo/bwp_shuaizhang.c",

"west":"/a/bowangpo/bwp_yingzhai.c",
 ]));
}

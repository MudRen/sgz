// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Fri May 27 19:33:55 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"–£≥°"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/anding/ad_yishiting.c",

"east":"/a/anding/ad_junying.c",

"south":"/a/anding/ad_chengzhongxin.c",

 ]));
}

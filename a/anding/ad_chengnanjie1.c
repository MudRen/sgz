// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Fri May 27 19:49:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"≥«ƒœΩ÷"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/anding/ad_chengnanjie2.c",

"east":"/a/anding/ad_xiaodian.c",

"west":"/a/anding/ad_guanzhai.c",

"north":"/a/anding/ad_chengzhongxin.c",

 ]));
}

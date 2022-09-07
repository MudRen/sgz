// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Fri May 27 19:47:37 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"πŸ’¨"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/anding/ad_chengnanjie1.c",
 ]));
}

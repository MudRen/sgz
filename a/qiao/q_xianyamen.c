// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 17:13:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"œÿ—√√≈"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/qiao/q_neitang.c",

"east":"/a/qiao/q_caishikou.c",
 ]));
}

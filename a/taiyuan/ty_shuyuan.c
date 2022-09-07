// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Thu May 26 20:54:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+" È‘∫"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/taiyuan/ty_beidajie2.c",
 ]));
}

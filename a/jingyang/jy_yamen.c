// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Fri May 27 18:49:37 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"—√√≈"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/jingyang/jy_datang.c",

"south":"/a/jingyang/jy_chengxijie.c",
 ]));
}

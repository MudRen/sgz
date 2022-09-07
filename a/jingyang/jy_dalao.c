// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Fri May 27 18:59:09 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"¥Û¿Œ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jingyang/jy_datang.c",
 ]));
}

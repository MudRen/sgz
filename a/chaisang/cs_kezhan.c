// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 20:52:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"øÕ’ª"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chaisang/cs_nanjiedong.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}

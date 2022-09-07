// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 20:19:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"¥ÛÃ√"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/daixian/dx_yamen.c",
 ]));
}

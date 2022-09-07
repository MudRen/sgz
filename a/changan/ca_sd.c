// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May  3 19:47:23 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"Êéµê"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/changan/ca_ycj1.c",
 ]));
}

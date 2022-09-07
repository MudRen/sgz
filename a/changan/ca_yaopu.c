// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May  3 21:31:25 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"Ò©ÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/changan/ca_nandajie.c",
 ]));
}

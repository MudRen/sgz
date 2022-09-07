// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May  3 21:13:57 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"Â³ÊÏÐÐ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/changan/ca_changlejie1.c",
 ]));
set_objects( (["/sgdomain/home/npc/llb.c" : 1]) );

}

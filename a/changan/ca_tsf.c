// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May  3 19:39:19 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"Ì«Ê¦¸®"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_fyt.c",

"north":"/a/changan/ca_xd.c",
 ]));
}

// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May  3 21:15:25 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"¶«´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/changan/ca_dongdajie1.c",

"south":"/a/changan/ca_xiaolu.c",

"north":"/a/changan/ca_changlejie1.c",
 ]));
}

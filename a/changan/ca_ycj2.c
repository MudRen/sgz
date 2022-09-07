// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue May  3 19:48:17 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"ÓÀ²ý½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/changan/ca_yongchangjie3.c",

"west":"/a/changan/ca_dangpu.c",

"south":"/a/changan/ca_ycj1.c",
 ]));
}

// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:33:47 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/changan/ca_ycj1.c",

"west":"/a/changan/ca_mz.c",

"south":"/a/changan/ca_xd.c",

"east":"/a/changan/ca_xdj1.c",
 ]));
}

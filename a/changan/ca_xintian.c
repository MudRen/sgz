// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:53:33 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/changan/ca_machang.c",
 ]));
}

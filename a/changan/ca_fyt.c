// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:39:49 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"����ͤ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/changan/ca_tsf.c",
 ]));
}

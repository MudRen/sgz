// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:15:55 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"С·"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/changan/ca_bingqipu.c",

"north":"/a/changan/ca_dongdajie2.c",
 ]));
}

// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:56:23 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_yanwuchang.c",

"east":"/a/changan/ca_beidajie3.c",

"north":"/a/changan/ca_beichengmen.c",

"west":"/a/changan/ca_beidajie1.c",
 ]));
}

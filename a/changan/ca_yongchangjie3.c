// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:51:05 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/changan/ca_machang.c",

"east":"/a/changan/ca_qianzhuang.c",

"south":"/a/changan/ca_ycj2.c",
 ]));
}

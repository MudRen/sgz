// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:55:19 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_beidajie1.c",
 ]));
}

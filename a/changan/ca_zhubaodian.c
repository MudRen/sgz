// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:18:19 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"�鱦��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_dongdajie1.c",
 ]));
}

// this room is created by buzzer.c
// driver is �������
// created date is Sun May  1 23:02:10 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"�о���"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/tongguan/yingzhai.c",
 ]));
}

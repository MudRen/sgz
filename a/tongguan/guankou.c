// this room is created by buzzer.c
// driver is �������
// created date is Sun May  1 23:03:38 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"�ؿ�"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/tongguan/dalu_left.c",

"east":"/a/tongguan/dalu.c",
 ]));
}

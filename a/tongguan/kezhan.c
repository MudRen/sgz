// this room is created by buzzer.c
// driver is �������
// created date is Sun May  1 23:06:44 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/tongguan/dalu.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}

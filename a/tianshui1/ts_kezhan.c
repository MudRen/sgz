// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:43:49 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/tianshui/ts_nandajie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}

// this room is created by buzzer.c
// driver is �������
// created date is Fri Jun  3 22:02:37 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/yunnan/yn_xidajie.c",
 ]));
set_objects( (["sgdomain/prison/yuzu.c" : 1 ]) );
}

// this room is created by buzzer.c
// driver is �������
// created date is Sat Jul 23 22:04:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jiangxia/jx_kedian.c",

"west":"/a/jiangxia/jx_beijie.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

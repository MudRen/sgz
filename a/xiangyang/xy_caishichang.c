// this room is created by buzzer.c
// driver is �������
// created date is Fri Jul 29 10:36:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
inherit STORE;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"���г�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xiangyang/xy_zahuodian.c",

"west":"/a/xiangyang/xy_tianchijie3.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

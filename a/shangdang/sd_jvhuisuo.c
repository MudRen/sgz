// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:36:26 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"�ۻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/shangdang/sd_dongdajie.c",
"north":"/a/shangdang/sd_liangcang.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:15:56 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"�ۻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hongnong/hn_liangcang.c",

"south":"/a/hongnong/hn_dongdajie.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

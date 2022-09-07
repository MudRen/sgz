// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Mon Jul 25 23:36:51 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"Á¸²Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chibi/cb_tian.c",

"west":"/a/chibi/cb_bingying.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

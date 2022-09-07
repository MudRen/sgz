// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat May  7 14:35:05 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"½È×Ó¹Ý"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/longxi/lx_beichenjie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/null.c" : 1]) );
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/shuihu.c");
}

// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Thu Jun  2 21:03:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"酒馆"+"%^RESET%^");
set_long("
    这里是鄱阳酒馆,门口写着一个招牌“太白楼”,四周的装饰
金壁辉煌，令人眼花缭乱,人来人往很是热闹。\n\n");
set_exits( ([
"west":"/a/poyang/py_lianbingchang.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

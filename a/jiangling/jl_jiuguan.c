// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 11:04:26 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"酒馆"+"%^RESET%^");
set_long("
    这里是江陵酒馆,门口写着一个招牌“太白楼”,四周的装饰
金壁辉煌，令人眼花缭乱,人来人往很是热闹。\n\n");
set_exits( ([
"south":"/a/jiangling/jl_shibanlu.c",
 ]));
//set_objects((["/sgdomain/obj/other/board.c" : ({ 1,"江陵的酒馆，门口挂着一白布“酒”字招牌。list列出货品，buy购买。\n\n"}) ]) );

add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );

}

// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Tue May  3 21:31:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"四海酒楼"+"%^RESET%^");
set_long("
    这里是长安最大的酒楼-四海酒楼，一幢高大的建筑上面挂
着金字的招牌，门口还有许多红灯笼。酒楼里面宾客如云，生意
好极了。你也可以在这里买一些吃的。list列出能买的食物，
buy指令购买。\n\n");
set_exits( ([
"west":"/a/changan/ca_nandajie.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );

}

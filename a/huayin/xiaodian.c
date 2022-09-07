// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Thu Apr 28 23:30:08 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"小店"+"%^RESET%^");
set_long("
    你走进村中唯一的一个小店，因为村中人少，这里的生意也不太
好。店小二正懒洋洋地坐在一旁打瞌睡。用list指令可以看出售中的
物品，buy指令购买。\n\n");
set_exits( ([
"north":"/a/huayin/xiaolu.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

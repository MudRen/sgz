// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri May  6 22:01:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"小店"+"%^RESET%^");
set_long("
    这是武关的一个路边小店，在这边关小镇看到一个小店可真让人
高兴。店里货物不多，但显得很干净整洁。店小二正在扫地呢。用list
指令可以看出售中的物品，buy指令购买。\n\n");
set_exits( ([
"north":"/a/wuguan/wg_dadao.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
}

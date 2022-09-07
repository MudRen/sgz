// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:28:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"成衣铺"+"%^RESET%^");
set_long("
    这是江陵街上的一所衣帽店，这里货品质量过硬，生意兴隆。
这里有衣服，鞋子，帽子出售。list指令列出货品，buy指令购买。\n\n");
set_exits( ([
"north":"/a/jiangling/jl_xiaoxiang.c",

"south":"/a/jiangling/jl_xiaolu.c",
 ]));
add_object("/sgdomain/obj/cloth/torso/buyi.c");
add_object("/sgdomain/obj/cloth/shoes/buxie.c");
add_object("/sgdomain/obj/cloth/shoes/pixue.c");
add_object("/sgdomain/obj/cloth/hats/guanjin.c");
}

// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Tue May  3 21:36:45 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"绸缎庄"+"%^RESET%^");
set_long("
    这是繁华的长安街上的一所很大的绸缎庄，这里货品琳琅
满目，生意兴隆。这里有衣服，鞋子，帽子出售。list指令列
出货品，buy指令购买。记得钱要带足哦。\n\n");
set_exits( ([
"south":"/a/changan/ca_xdj1.c",
 ]));
add_object("/sgdomain/obj/cloth/torso/buyi.c");
add_object("/sgdomain/obj/cloth/torso/changpao.c");
add_object("/sgdomain/obj/cloth/torso/choup.c");
add_object("/sgdomain/obj/cloth/torso/hechang.c");
add_object("/sgdomain/obj/cloth/torso/jinp.c");
add_object("/sgdomain/obj/cloth/torso/longpao.c");
add_object("/sgdomain/obj/cloth/shoes/buxie.c");
add_object("/sgdomain/obj/cloth/shoes/pixue.c");
add_object("/sgdomain/obj/cloth/hats/guanjin.c");
add_object("/sgdomain/obj/cloth/hats/jinkui.c");
add_object("/sgdomain/obj/cloth/hats/yinkui.c");
}

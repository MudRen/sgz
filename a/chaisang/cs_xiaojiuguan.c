// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Mon May 30 20:55:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"小酒馆"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chaisang/cs_nanjiexi.c",
 ]));
set_objects((["/sgdomain/obj/other/board.c" : ({ 1,"柴桑的酒馆，门口挂着一白布“酒”字招牌。list列出货品，buy购买。\n院子有一口井，清凉的井水可以灌到水壶里。\n\n"}) ]) );

add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

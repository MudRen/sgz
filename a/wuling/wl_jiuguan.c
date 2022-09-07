// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:31:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"酒馆"+"%^RESET%^");
set_long("
    酒楼里桌椅洁净。座中客人衣饰豪奢，十之八九是富商大
贾。武陵地处交通要地，来这吃饭的人还真不少。list列出货
品，buy购买。\n\n");
set_exits( ([
"west":"/a/wuling/wl_xiaoxiang.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}

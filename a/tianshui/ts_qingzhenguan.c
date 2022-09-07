// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:43:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"清真馆"+"%^RESET%^");
set_long("
    这里是西北风味的回族清真餐馆，门口站着一位大胡子的
老板，这里有特色的拉面，羊肉。店小二热情地来招呼你，这
位客官，要点什么？list可以列出货品价格，buy购买。\n\n");
set_exits( ([
"east":"/a/tianshui/ts_nandajie1.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );

}

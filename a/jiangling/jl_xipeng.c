// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 10:03:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"戏棚"+"%^RESET%^");
set_long("
    这里是江陵的戏棚,台上正演着“霸王别姬”，很多客人
在台下叫喊喝彩,津津有味的看着戏。一个小贩在兜售小吃,
一个小孩贼头贼脑的盯着客人的钱袋。南面是后台。\n\n");
set_exits( ([
"south":"/a/jiangling/jl_houtai.c",

"north":"/a/jiangling/jl_yaopu.c",

"east":"/a/jiangling/jl_dongchengmen.c",
 ]));
}

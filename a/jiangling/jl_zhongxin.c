// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:26:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"中心广场"+"%^RESET%^");
set_long("
    这里是江陵城的中心广场,车水马龙很热闹,广场中间是
一片青青的草地，有许多小贩走来去贩卖各种吃的玩的。西
面是一条小路。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_xiaolu.c",

"south":"/a/jiangling/jl_ruipinglu.c",

"north":"/a/jiangling/jl_ruipinglu3.c",
 ]));
}

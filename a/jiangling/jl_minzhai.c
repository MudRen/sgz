// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:38:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"民宅"+"%^RESET%^");
set_long("
    这里是民宅,几个居民聚在一起,低声说这悄悄话。
从西边瑞平路走来几个人，不知道在找什么东西。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu5.c",
 ]));
}

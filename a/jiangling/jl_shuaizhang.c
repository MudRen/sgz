// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:21:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"帅帐"+"%^RESET%^");
set_long("
    这里是江陵帅帐,室内非常宽敞,摆置着一张大大的
精致木桌,两旁摆着两排精致的凳子，两面的墙上挂着几
幅名画。这里便是江陵太守平时处理内政和军务的地方。\n\n");
set_exits( ([
"east":"/a/jiangling/jl_bingying.c",
 ]));
}

// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:23:54 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"铁匠铺"+"%^RESET%^");
set_long("
    铁匠正在吭哧吭哧打一把烧红了的钢剑，伙计在一旁拉着风箱，
右边的墙上挂着各式各样的刀剑，其中不乏质量上乘的货品。用list
指令看兵器的价格，buy指令购买。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu1.c",
 ]));
}

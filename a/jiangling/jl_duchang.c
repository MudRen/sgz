// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:40:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"赌场"+"%^RESET%^");
set_long("
    这里是赌场,一堆人围着桌子在赌牌九,两个彪悍的
打手在来回巡视。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu3.c",
 ]));
}

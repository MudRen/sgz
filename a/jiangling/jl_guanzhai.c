// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:25:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"官宅"+"%^RESET%^");
set_long("
    这里是江陵的官宅,忙碌了一天的官员，在家里休息。\n\n");
set_exits( ([
"east":"/a/jiangling/jl_ruipinglu.c",
 ]));
}

// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:38:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"马场"+"%^RESET%^");
set_long("
    这里是马场,江陵的军马都养在这里。\n\n");
set_exits( ([
"east":"/a/jiangling/jl_ruipinglu5.c",
 ]));
}

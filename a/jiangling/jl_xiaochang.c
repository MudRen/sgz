// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:19:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"校场"+"%^RESET%^");
set_long("
    这里是江陵校场,在此你可以看到一队队官兵正在操练，
他们是打胜仗的根本。只要你有兵符，你就可以调动数万大
军上阵杀敌。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu2.c",
 ]));
}

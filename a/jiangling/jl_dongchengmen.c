// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 10:08:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"东城门"+"%^RESET%^");
set_long("
    这里是江陵的东城门,高大的城墙上写着
诺大的两个字「"+"%^MAGENTA%^"+"江陵"+"%^RESET%^"+"」。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_xipeng.c",
 ]));
}

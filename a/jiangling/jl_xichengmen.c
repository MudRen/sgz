// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:28:02 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"西城门"+"%^RESET%^");
set_long("
    这里是江陵的西城门,高大城墙上写着诺大的两个
字「"+"%^MAGENTA%^"+"江陵"+"%^RESET%^"+"」。\n\n");
set_exits( ([
"east":"/a/jiangling/jl_xiaolu.c",
 ]));
}

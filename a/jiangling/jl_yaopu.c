// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 10:00:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"药铺"+"%^RESET%^");
set_long("
    这里是江陵唯一的药铺，门口写着一个招牌“一品堂”。\n\n");
set_exits( ([
"south":"/a/jiangling/jl_xipeng.c",

"north":"/a/jiangling/jl_shibanlu.c",
 ]));
}

// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:29:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"客栈"+"%^RESET%^");
set_long("
    这里是江陵最大的客栈,由于连年战乱,生意很冷淡。\n\n");
set_exits( ([
"south":"/a/jiangling/jl_xiaoxiang.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );

}

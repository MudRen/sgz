// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Thu May 26 21:57:10 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"衙门"+"%^RESET%^");
set_long("
    这里是江陵衙门,一些居民堵在门口,看着大堂里面审案子。\n\n");
set_exits( ([
"south":"/a/jiangling/jl_datang.c",

"north":"/a/jiangling/jl_xiaolu.c",
 ]));
}

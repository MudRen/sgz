// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:27:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"С·"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jiangling/jl_yamen.c",

"north":"/a/jiangling/jl_chengyipu.c",

"west":"/a/jiangling/jl_xichengmen.c",

"east":"/a/jiangling/jl_zhongxin.c",
 ]));
}

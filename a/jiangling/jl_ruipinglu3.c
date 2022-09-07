// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Mon May  9 09:39:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"ÈðÆ½Â·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jiangling/jl_duchang.c",

"west":"/a/jiangling/jl_qianzhuang.c",

"north":"/a/jiangling/jl_ruipinglu4.c",

"south":"/a/jiangling/jl_zhongxin.c",
 ]));
}

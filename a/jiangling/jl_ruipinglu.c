// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:16:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��ƽ·"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/jiangling/jl_zhongxin.c",

"west":"/a/jiangling/jl_guanzhai.c",

"south":"/a/jiangling/jl_ruipinglu1.c",

"east":"/a/jiangling/tmp.c",
 ]));
}

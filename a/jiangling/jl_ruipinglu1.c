// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:17:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��ƽ·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jiangling/jl_tiejiangpu.c",

"south":"/a/jiangling/jl_ruipinglu2.c",

"north":"/a/jiangling/jl_ruipinglu.c",
 ]));
}

// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:53:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"ʯ��·"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/jiangling/jl_jiuguan.c",

"south":"/a/jiangling/jl_yaopu.c",

"west":"/a/jiangling/jl_ruipinglu4.c",
 ]));
}

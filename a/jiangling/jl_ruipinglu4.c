// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:30:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��ƽ·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jiangling/jl_shibanlu.c",

"south":"/a/jiangling/jl_ruipinglu3.c",

"north":"/a/jiangling/jl_ruipinglu5.c",

"west":"/a/jiangling/jl_xiaoxiang.c",
 ]));
}

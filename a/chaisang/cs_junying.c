// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Mon May 30 21:04:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"军营"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/chaisang/cs_xiaochang.c",

"east":"/a/chaisang/cs_yishiting.c",

"south":"/a/chaisang/cs_beijiedong.c",
 ]));
set_objects(([M_BOARD : ({ 1,"这里的榜文经常发布国家大事，瞧瞧去。\n\n木牌上挂着 "+"%^MAGENTA%^"+"柴桑留言榜"+"%^RESET%^", "city.chaisang" }) ]) );
}

// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri May  6 22:02:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"武关关口"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuguan/wg_dalu.c",

"west":"/a/wuguan/wg_dadao.c",
 ]));
set_objects(([M_BOARD : ({ 1,"官兵把守着武关的城门口。\n\n城墙上挂着"+"%^MAGENTA%^"+"武关留言牌"+"%^RESET%^", "city.wuguan" }) ]) );
}

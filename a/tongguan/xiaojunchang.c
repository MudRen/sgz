// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  1 23:07:48 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"校军场"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/tongguan/dalu_right.c",
 ]));
set_objects(([M_BOARD : ({ 1,"校军场上一员武将正训练士兵们排出各种进攻阵型。\n\n入口处立着一块"+"%^MAGENTA%^"+"长安留言牌"+"%^RESET%^", "city.tongguan" }) ]) );
}

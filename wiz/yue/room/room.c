//  杂货铺
// ly_zahp.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
inherit STORE;
void setup(){
    set_area("ly_area");
    set_light(50);
    set_brief(""+YEL+"杂货铺"+NOR+"");
    set_long(
"    此处是洛阳城南大街上的一家小杂货铺。屋子不大，靠墙支着个
木架，摆着几件待卖的物事，墙角堆放着几口皮箱，看来存放着不少
货物。一个小伙计拿着个小条帚掸着柜台上的灰尘，而铺子的老板正
满脸堆笑地看着你，运气好的话，可以在这里买到些不错的玩意。从
小门出去就是南大街。\n\n");
    set_exits( ([
        "west" :  __DIR__+"ly_ndj1.c",
    ]) );
}

/* workroom.c
** Coded by 玄冰@三国
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>

inherit INDOOR_ROOM;

void setup(){
    set_area("westside");
    set_light(20);
        set_brief(""+HIR+"暖香阁"+NOR+"");
    set_long("
    暖香阁内只有一张书桌，搁着几支毛笔，空空的再无它物。
显然屋子的女主人并不喜欢脂脂粉粉。然而奇怪的是整个房间仍然
散发着一种异香。
\n\n"
);
    set_exits( ([
	"out" : __DIR__+"park.c",
    ]));
    set_objects( ([
  __DIR__+"shabed.c":1,
    ]) );
}

int smell()
{
    write ("一股不知名的异香扑鼻而入，啊。。。你不由的痴了。。。\n");
    return 1;
}

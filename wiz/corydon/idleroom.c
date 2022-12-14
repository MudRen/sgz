/* idleroom.c
** Coded by 玄冰@三国
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>

inherit INDOOR_ROOM;



void setup(){
        object door;
    set_light(50);
    set_area("westside");
        set_brief(""+YEL+"呆呆屋"+NOR+"");
    set_long("
    这里似乎是主人的书房和卧室，不过进来的人一般都会先为在哪
儿找个位置坐头疼几分钟，因为除了电脑前面的椅子之外，其他地方
都随意地放了些东西。屋里有一个大书架，上面的书已经蒙上了厚厚
的灰尘，可见此间主人已久未读书了。书架旁边是一张大书桌，上面
堆着电脑、打印机之类的东西，
\n\n");
    set_exits( ([
        "down" : __DIR__+"ex_room.c",
        "goup" : __DIR__+"workroom.c",
    ]) );
    set_enter_msg("idleroom","\n$N一不小心钻了进来，才发现自己掉进了一个密室。\n\n");
    set_objects( ([
//         __DIR__"obj/idle_door" : ({ "goup" }), // has bugs fix it please :)
    ]) );
  set_default_exit( "\n门好像还没有开嘛，搞什么飞机。\n\n");
  door = present( "door");
  if(!objectp(door)) return ;
  if( !door->query_closed())
  door->do_on_open();
}

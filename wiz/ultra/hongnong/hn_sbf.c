/* hn_cc.c
** Coded by 月神@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
   set_area("hn_area");
    set_light(50);
    set_brief(YEL+"守备府"+NOR);
    set_long(
"  守备府看门的那两个家将凶神恶煞.据说上回有个毛头小子
不知死活的闯进去,结果呢?嘿嘿,横着被抬出来.看来还是
躲远点好"
);
   set_room_state("valid_start");
    set_exits( ([
    "south" : __DIR__+"hn_xj1.c",
    ]) );
    set_objects( ([
    ]) );
}

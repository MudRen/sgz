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
    set_brief(YEL+"城中"+NOR);
    set_long(
"    这里就是弘农的城中心。虽然弘农城很小，但城中心也是很大。
路口人来人往。东边是东街，远远的一些兵队。西边是西街，那边有
一家客栈，去那休息休息吧。\n
");
   set_room_state("valid_start");
    set_exits( ([
    "west" : __DIR__+"hn_xj1.c",
    "east" : __DIR__+"hn_dj1",
"southwest" :  __DIR__+"hn_yizhan.c",
    ]) );
    set_objects( ([
    ]) );
}

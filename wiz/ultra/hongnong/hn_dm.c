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
    set_brief(YEL+"东门"+NOR);
    set_long(
"    这是东城门，城门正上方刻着“东门”两个楷书大字，城墙上
贴着几张官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最
好小心为妙。\n\n"
);
   set_room_state("valid_start");
    set_exits( ([
    "west" : __DIR__+"hn_dj2",
    ]) );
    set_objects( (["/sgdomain/area/town/hongnong/npc/bing.c" : 2]) );
}

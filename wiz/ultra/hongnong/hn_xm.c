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
    set_brief(YEL+"西门"+NOR);
    set_long(
"    这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。
城门正上方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通
缉告示(gaoshi)。\n\n"
);
   set_room_state("valid_start");
    set_exits( ([
    "east" : __DIR__+"hn_xj2",
    ]) );
    set_objects( (["/sgdomain/area/town/hongnong/npc/bing.c" : 2]) );
}

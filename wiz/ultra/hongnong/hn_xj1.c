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
    set_brief(YEL+"西街"+NOR);
    set_long(
"    你走在一条狭窄黄土街上，东面就快到城中心了。北边是守备府
，一队队官兵在那里出入。看来哪并不是好玩的地方。\n\n"
);
   set_room_state("valid_start");
    set_exits( ([
    "west" : __DIR__+"hn_xj2.c",
    "north" : __DIR__+"hn_sbf",
    "east" : __DIR__+"hn_cz",
    ]) );
    set_objects( ([
    ]) );
}

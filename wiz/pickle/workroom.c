/*
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup(){
    set_area("vinegar_bottle");
    set_light(50);
    set_brief(GRN"醋坛子"NOR);

    set_long("  
一个空空的醋坛子，泛着一股酸气。
");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "zatan" : __DIR__+"chatroom.c", 
    ]) );
}

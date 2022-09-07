//  小道 road4.c
// made by benben
// cl_road4.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"小道"+NOR+"");
    set_long("    遥望卧龙冈，果然清景异常。不远处有座小桥，路边是个小酒店，
有人在里面击桌而歌，或许是什么隐世高人。\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_road5.c",
        "east" :  __DIR__+"cl_bridge.c",
        "north" :  __DIR__+"cl_jiud.c",
    ]) );
}

// 狄道小山头
// dd_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"小山头"+NOR+"");
    set_long("  一条小路直通向一片开阔的地方，难道那就是出口。旁边还有
一条很多人踩过的小道，但看起来弯弯曲曲的。\n\n");
    set_exits( ([
        "northwest" :  __DIR__+"dd_wl.c",
        "north" :  __DIR__+"dd_xy.c",
        "south" :  __DIR__+"dd_xst.c",
    ]) );
}



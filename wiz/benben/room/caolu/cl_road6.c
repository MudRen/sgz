//  小道6 road6.c
// made by benben
// cl_road6.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"小道"+NOR+"");
    set_long("    往西20里地就是襄阳城了，东面有一座大山，林麓幽深，必有高
人隐居。\n\n");
    set_exits( ([
        "west" :  __DIR__+"xiangyang.c",
        "east" :  __DIR__+"cl_road5.c",
    ]) );
}

//  小道5 road5.c
// made by benben
// cl_road5.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"小道"+NOR+"");
    set_long("    大山看起来近了，你禁不住加快了脚步。\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_road6.c",
        "east" :  __DIR__+"cl_road4.c",
    ]) );
set_objects( ([ "/wiz/benben/NPC/farmer.c" : 1 ]) );
}

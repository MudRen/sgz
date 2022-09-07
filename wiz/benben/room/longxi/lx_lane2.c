//  –°œÔ by benben
// lx_lane2.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--–°œÔ--"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "east" :  __DIR__+"lx_lane3.c",
        "west" :  __DIR__+"lx_lane1.c",
        "north" : __DIR__+"lx_mzh1.c",
    ]) );
}

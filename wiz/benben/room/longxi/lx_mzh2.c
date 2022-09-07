//  √Ò’¨ by benben
// lx_mzh2.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--√Ò’¨--"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "south" :  __DIR__+"lx_lane3.c",
    ]) );
}

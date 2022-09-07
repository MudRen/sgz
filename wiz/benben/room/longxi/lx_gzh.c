//  πŸ’¨ by benben
// lx_gzh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--πŸ’¨--"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "east" :  __DIR__+"lx_lane1.c",
    ]) );
}

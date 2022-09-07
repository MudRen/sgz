//  —√√≈ by benben
// xy_ym.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"—√√≈"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "east" :  __DIR__+"xy_nst1.c",
        "west" :  __DIR__+"xy_dt.c",
    ]) );
}

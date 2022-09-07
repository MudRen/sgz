//  æ∆π› by benben
// xy_jg.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"æ∆π›"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "west" :  __DIR__+"xy_sst1.c",
    ]) );
}

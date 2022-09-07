// ‘∆”Í∏Û  by Benben
// ty_yunyu.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"‘∆”Í∏Û"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "east" :  __DIR__+"ty_nst1.c",
    ]) );
}

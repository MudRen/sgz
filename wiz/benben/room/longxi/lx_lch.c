//  ¡∏≤÷ by benben
// lx_lch.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--¡∏≤÷--"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "north" :  __DIR__+"lx_qmst2.c",
    ]) );
}

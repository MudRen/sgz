// Ê‰’æ  by Benben
// ty_yizhan.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"Ê‰’æ"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "south" :  __DIR__+"ty_est2.c",
    ]) );
}

// ‘”ªı∆Ã  by Benben
// ty_grocery.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"‘”ªı∆Ã"+NOR+"");
    set_long("    √Ë ˆ°£\n");
    set_exits( ([
        "west" :  __DIR__+"ty_sst1.c",
    ]) );
}

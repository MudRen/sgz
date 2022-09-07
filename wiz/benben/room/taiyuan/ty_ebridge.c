//  ¶«µõÇÅ  by Benben
// ty_ebridge.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"¶«µõÇÅ"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "west" :  __DIR__+"ty_egate.c",
    ]) );
}

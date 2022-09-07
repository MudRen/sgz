//  ´º»ªÂ¥ by benben
// xy_cch.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"´º»ªÂ¥"+NOR+"");
    set_long("    ÃèÊö¡£\n\n");
    set_exits( ([
        "south" :  __DIR__+"xy_est2.c",
    ]) );
}

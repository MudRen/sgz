//  ±øÆ÷ÆÌ by benben
// xy_weapon.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"±øÆ÷ÆÌ"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "north" :  __DIR__+"xy_wst1.c",
    ]) );
}

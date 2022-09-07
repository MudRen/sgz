//  ´óÌÃ by benben
// xy_dt.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"´óÌÃ"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "east" :  __DIR__+"xy_ym.c",
        "north" : __DIR__+"xy_jail.c"
    ]) );
}

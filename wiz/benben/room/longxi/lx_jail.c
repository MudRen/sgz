//  ÀÎÓü by benben
// lx_jail.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--ÀÎÓü--"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "east" :  __DIR__+"lx_dt.c",
    ]) );
}

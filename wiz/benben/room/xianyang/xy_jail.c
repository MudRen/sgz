//  ÀÎÓü by benben
// xy_jail.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"ÀÎÓü"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "south" : __DIR__+"xy_dt.c"
    ]) );
}

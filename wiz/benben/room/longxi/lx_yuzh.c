//  ÓñÕæÂ¥ by benben
// lx_yuzh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--ÓñÕæÂ¥--"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "south" :  __DIR__+"lx_qmst4.c",
    ]) );
}

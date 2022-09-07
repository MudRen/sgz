// Ì«Ñ§ÌÃ  by Benben
// ty_taixue.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"Ì«Ñ§ÌÃ"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "east" :  __DIR__+"ty_nst2.c",
    ]) );
}

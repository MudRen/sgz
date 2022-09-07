// ²èÂ¥  by Benben
// ty_tea.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"²èÂ¥"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "south" :  __DIR__+"ty_est1.c",
    ]) );
}

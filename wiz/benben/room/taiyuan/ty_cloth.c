// ²¼×¯  by Benben
// ty_cloth.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"²¼×¯"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "north" :  __DIR__+"ty_wst1.c",
    ]) );
}

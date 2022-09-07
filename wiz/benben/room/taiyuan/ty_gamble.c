// ¶Ä³¡  by Benben
// ty_gamble.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"¶Ä³¡"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "south" :  __DIR__+"ty_wst1.c",
    ]) );
}

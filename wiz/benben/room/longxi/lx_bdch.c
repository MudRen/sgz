//  布道场(？) by benben
// lx_yzh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--布道场--"+NOR+"");
    set_long("    描述。\n");
    set_exits( ([
        "west" :  __DIR__+"lx_dnst2.c",
    ]) );
}

// ±øÓª by Benben
// ty_camp4.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"±øÓª"+NOR+"");
    set_long("    ÃèÊö¡£\n");
    set_exits( ([
        "east" :  __DIR__+"ty_sst2.c",
        "west" :  __DIR__+"ty_camp3.c",
    ]) );
}

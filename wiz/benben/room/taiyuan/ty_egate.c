//  东城门  by Benben
// ty_egate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"东城门"+NOR+"");
    set_long("    描述。\n");
    set_exits( ([
        "east" :  __DIR__+"ty_ebridge.c",
        "west" :  __DIR__+"ty_est2.c",
    ]) );
}

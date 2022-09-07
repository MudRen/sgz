//  城中心  by Benben
// ty_center.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"城中心"+NOR+"");
    set_long("    描述。\n");
    set_exits( ([
        "east" :  __DIR__+"ty_est1.c",
        "west" :  __DIR__+"ty_wst1.c",
        "south" : __DIR__+"ty_sst1.c",
        "north" : __DIR__+"ty_nst1.c"
    ]) );
}

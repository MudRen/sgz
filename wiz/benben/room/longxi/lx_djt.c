//  点将台 by benben
// lx_djt.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--点将台--"+NOR+"");
    set_long("    描述。通向天水。\n");
    set_exits( ([
        "east" :  __DIR__+"lx_qmst1.c",
    ]) );
}

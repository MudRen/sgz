//  前门大街 by benben
// lx_qmst1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--前门大街--"+NOR+"");
    set_long("    描述。\n");
    set_exits( ([
        "east" :  __DIR__+"lx_qmst2.c",
        "west" :  __DIR__+"lx_djt.c",
        "south" : __DIR__+"lx_jlch.c",
    ]) );
}

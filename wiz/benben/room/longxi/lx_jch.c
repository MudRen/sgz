//  У�� by benben
// lx_jch.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--У��--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" :  __DIR__+"lx_camp.c",
    ]) );
}

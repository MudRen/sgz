//  ��� by benben
// xy_fch.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"���"+NOR+"");
    set_long("    ������\n\n");
    set_exits( ([
        "south" :  __DIR__+"xy_nchx3.c",
    ]) );
}

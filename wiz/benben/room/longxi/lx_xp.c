//  Ϸ�� by benben
// lx_xp.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--Ϸ��--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "south" :  __DIR__+"lx_bhst3.c",
    ]) );
}

//  ǰ�Ŵ�� by benben
// lx_bhst3.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--��徽�--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"lx_kd.c",
        "west" :  __DIR__+"lx_lane3.c",
        "south" : __DIR__+"lx_bhst2.c",
        "north" : __DIR__+"lx_xp.c",
    ]) );
}

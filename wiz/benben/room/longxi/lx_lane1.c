//  С�� by benben
// lx_lane1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--С��--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"lx_lane2.c",
        "west" :  __DIR__+"lx_gzh.c",
        "north" : __DIR__+"lx_temple.c",
    ]) );
}

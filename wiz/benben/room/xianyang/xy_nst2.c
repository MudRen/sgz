//  ����� by benben
// xy_nst2.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"�����"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"xy_jy.c",
        "west" :  __DIR__+"xy_ysh.c",
        "south" : __DIR__+"xy_nst1.c",
        "north" : __DIR__+"xy_nst3.c"
    ]) );
}

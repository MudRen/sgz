//  ����� by benben
// xy_est1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xy_area");
    set_light(50);
    set_brief(""+YEL+"�����"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"xy_est2.c",
        "west" :  __DIR__+"xy_center.c",
    ]) );
}

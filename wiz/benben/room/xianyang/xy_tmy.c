//  ̽��Ӫ by benben
// xy_tmy.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"̽��Ӫ"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" :  __DIR__+"xy_wst2.c",
    ]) );
}

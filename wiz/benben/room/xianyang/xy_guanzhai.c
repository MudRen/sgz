//  ��լ by benben
// xy_guanzhai.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"��լ"+NOR+"");
    set_long("    ������\n\n");
    set_exits( ([
        "south" :  __DIR__+"xy_nst3.c",
    ]) );
}

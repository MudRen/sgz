//  ҽ�� by benben
// xy_ysh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"ҽ��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"xy_nst2.c",
    ]) );
}

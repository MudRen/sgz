//  У�� by benben
// xy_jch.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"У��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" : __DIR__+"xy_jy.c"
    ]) );
}

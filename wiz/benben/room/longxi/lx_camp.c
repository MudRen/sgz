//  ��Ӫ by benben
// lx_camp.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--��Ӫ--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" :  __DIR__+"lx_qmst3.c",
        "south" :  __DIR__+"lx_jch.c",
    ]) );
}

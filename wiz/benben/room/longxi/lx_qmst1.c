//  ǰ�Ŵ�� by benben
// lx_qmst1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--ǰ�Ŵ��--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"lx_qmst2.c",
        "west" :  __DIR__+"lx_djt.c",
        "south" : __DIR__+"lx_jlch.c",
    ]) );
}

//  ǰ�Ŵ�� by benben
// lx_qmst5.c 
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
        "east" :  __DIR__+"lx_egate.c",
        "west" :  __DIR__+"lx_qmst4.c",
        "north" : __DIR__+"lx_bhst1.c",
        "south" : __DIR__+"lx_dnst1.c",
    ]) );
}

//  �㽫̨ by benben
// lx_djt.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--�㽫̨--"+NOR+"");
    set_long("    ������ͨ����ˮ��\n");
    set_exits( ([
        "east" :  __DIR__+"lx_qmst1.c",
    ]) );
}

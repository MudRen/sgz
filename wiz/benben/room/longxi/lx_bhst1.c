//  ǰ�Ŵ�� by benben
// lx_bhst1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--��徽�--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"lx_dumpling.c",
        "south" : __DIR__+"lx_qmst5.c",
        "north" : __DIR__+"lx_shst2.c",
    ]) );
}

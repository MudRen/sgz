//  �ϳ��� by benben
// xy_nchx2.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"�ϳ���"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"xy_temple.c",
        "west" :  __DIR__+"xy_nchx1.c",
        "north" : __DIR__+"xy_mzh.c"
    ]) );
}

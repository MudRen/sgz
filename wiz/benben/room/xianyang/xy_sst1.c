//  �ϴ�� by benben
// xy_sst1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xy_area");
    set_light(50);
    set_brief(""+YEL+"�ϴ��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"xy_jg.c",
        "west" :  __DIR__+"xy_mch.c",
        "north" : __DIR__+"xy_center.c",
        "south" : __DIR__+"xy_nchx1.c"
    ]) );
}

//  �����  by Benben
// ty_nst1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"�����"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"ty_tshf.c",
        "west" :  __DIR__+"ty_yunyu.c",
        "south" : __DIR__+"ty_center.c",
        "north" : __DIR__+"ty_nst2.c"
    ]) );
}

//  �ϳ���  by Benben
// ty_sgate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"�ϳ���"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "south" : __DIR__+"ty_sbridge.c",
        "north" : __DIR__+"ty_sst2.c"
    ]) );
}

//  �ϵ���  by Benben
// ty_sbridge.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"�ϵ���"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" :  __DIR__+"ty_sgate.c",
    ]) );
}

//  �ϴ��  by Benben
// ty_sst2.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"�ϴ��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"ty_iron.c",
        "west" :  __DIR__+"ty_camp4.c",
        "south" : __DIR__+"ty_sgate.c",
        "north" : __DIR__+"ty_sst1.c"
    ]) );
}

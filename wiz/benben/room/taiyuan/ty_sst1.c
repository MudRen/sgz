//  �ϴ��  by Benben
// ty_sst1.c 
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
        "east" :  __DIR__+"ty_grocery.c",
        "west" :  __DIR__+"ty_bank.c",
        "south" : __DIR__+"ty_sst2.c",
        "north" : __DIR__+"ty_center.c"
    ]) );
}

//  �����  by Benben
// ty_est2.c 
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
        "east" :  __DIR__+"ty_egate.c",
        "west" :  __DIR__+"ty_est1.c",
        "south" : __DIR__+"ty_medicine.c",
        "north" : __DIR__+"ty_yizhan.c"
    ]) );
}

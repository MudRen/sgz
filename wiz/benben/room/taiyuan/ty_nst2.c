//  �����  by Benben
// ty_nst2.c 
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
        "east" :  __DIR__+"ty_shuyuan.c",
        "west" :  __DIR__+"ty_taixue.c",
        "south" : __DIR__+"ty_nst1.c",
        "north" : __DIR__+"ty_nst3.c"
    ]) );
}

// ��  by Benben
// ty_horse.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" :  __DIR__+"ty_wst2.c",
    ]) );
}

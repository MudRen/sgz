// ̫ʦ��  by Benben
// ty_tshf.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"̫ʦ��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "west" :  __DIR__+"ty_nst1.c",
    ]) );
}

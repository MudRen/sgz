// �ӻ���  by Benben
// ty_grocery.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"�ӻ���"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "west" :  __DIR__+"ty_sst1.c",
    ]) );
}

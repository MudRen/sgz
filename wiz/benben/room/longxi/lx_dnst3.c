//  ���Ͻ� by benben
// lx_dnst3.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--���Ͻ�--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "west" :  __DIR__+"lx_jjf.c",
        "north" :  __DIR__+"lx_dnst2.c",
    ]) );
}

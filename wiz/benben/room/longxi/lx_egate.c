//  ������ by benben
// lx_egate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--������--"+NOR+"");
    set_long("    ������ͨ����ˮ��\n");
    set_exits( ([
        "west" :  __DIR__+"lx_qmst5.c",
        "east" :  __DIR__+"?_?.c",
    ]) );
}

//  ��˧Ӫ��  by Benben
// ty_camp3.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"��˧Ӫ��"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"ty_camp4.c",
    ]) );
}

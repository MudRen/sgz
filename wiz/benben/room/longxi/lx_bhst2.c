//  ǰ�Ŵ�� by benben
// lx_bhst2.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--��徽�--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "east" :  __DIR__+"lx_photo.c",
        "south" : __DIR__+"lx_bhst1.c",
        "north" : __DIR__+"lx_bhst3.c",
    ]) );
}

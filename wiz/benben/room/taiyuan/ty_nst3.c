// �����   by Benben
// ty_nst3.c 
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
        "east" :  __DIR__+"ty_camp1.c",
        "west" :  __DIR__+"ty_camp2.c",
        "south" : __DIR__+"ty_nst2.c",
        "north" : __DIR__+"ty_palace.c"
    ]) );
}

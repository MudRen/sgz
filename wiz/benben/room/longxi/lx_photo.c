//  相馆  三国时候有相馆吗？ by benben
// lx_photo.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--相馆--"+NOR+"");
    set_long("    描述。\n");
    set_exits( ([
        "west" :  __DIR__+"lx_bhst2.c",
    ]) );
}

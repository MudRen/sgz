//  东城门 by benben
// lx_egate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--东城门--"+NOR+"");
    set_long("    描述。通向天水。\n");
    set_exits( ([
        "west" :  __DIR__+"lx_qmst5.c",
        "east" :  __DIR__+"?_?.c",
    ]) );
}

//  Œ‘ “
// cl_wsh.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"Œ‘ “"+NOR+"");
    set_long("    Œ‘ “°£\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_zht.c",
    ]) );
}

//  东城门
// xy_egate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"东城门"+NOR+"");
    set_long("东城门。通向泾阳。\n\n");
    set_exits( ([
        "east" :  __DIR__+"?_?.c",
        "west" :  __DIR__+"xy_est2.c",
    ]) );
}

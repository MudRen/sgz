//  西城门 by benben
// xy_wgate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"西城门"+NOR+"");
    set_long("西城门。通向陈仓。\n\n");
    set_exits( ([
        "east" :  __DIR__+"xy_wst2.c",
        "west" :  __DIR__+"?_?.c",
    ]) );
}

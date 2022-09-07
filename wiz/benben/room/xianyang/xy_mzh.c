//  √Ò’¨ by benben
// xy_mzh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xy_area");
    set_light(50);
    set_brief(""+YEL+"√Ò’¨"+NOR+"");
    set_long("    √Ë ˆ°£\n\n");
    set_exits( ([
        "south" :  __DIR__+"xy_nchx2.c",
    ]) );
}

// 御林军营  by Benben
// ty_camp1.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("ty_area");
    set_light(50);
    set_brief(""+YEL+"御林军营"+NOR+"");
    set_long("    描述。\n");
    set_exits( ([
        "west" :  __DIR__+"ty_nst3.c",
    ]) );
}

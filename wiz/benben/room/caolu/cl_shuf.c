//  书房
// cl_shuf.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"书房"+NOR+"");
    set_long("    卧龙先生的书房\n\n");
    set_exits( ([
        "east" :  __DIR__+"cl_zht.c",
    ]) );
}

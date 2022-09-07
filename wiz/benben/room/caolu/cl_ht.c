//  ∫ÛÃ√
// cl_ht.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"∫ÛÃ√"+NOR+"");
    set_long("«Îº”√Ë ˆ°£\n\n");
    set_exits( ([
        "north" :  __DIR__+"cl_hy.c",
        "south" :  __DIR__+"cl_zht.c",
    ]) );
}

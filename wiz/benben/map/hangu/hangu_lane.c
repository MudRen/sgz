//  函谷关 by benben
// hangu_lane.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"通往函谷关的小道"+NOR+"");
    set_long("    一条小道，往东可以望见弘农城，往西就是函谷关了。
\n\n");
    set_exits( ([
        "west" :  __DIR__+"hangu_guankou.c",
        "east" :  __DIR__+"    ?",
    ]) );
}


//  函谷关 by benben
// hangu_guankou.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"函谷关"+NOR+"");
    set_long("    这里是函谷关，过了关就是渭水，是通往长安的必经之地。
\n\n");
    set_exits( ([
        "north" :  __DIR__+"hangu_camp.c",
        "east" :  __DIR__+"hangu_lane.c",
    ]) );
}


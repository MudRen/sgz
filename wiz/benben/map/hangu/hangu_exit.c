//  函谷关 by benben
// hangu_exit.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"函谷关"+NOR+"");
    set_long("    这里是函谷关，往西是潼关，北面是渭水，过了关往东就是弘农。
\n\n");
    set_exits( ([
        "south" :  __DIR__+"hangu_camp.c",
        "north" :  __DIR__+"weishui.c",
    ]) );
}


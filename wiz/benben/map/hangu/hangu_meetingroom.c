//  函谷关 by benben
// hangu_meetingroom.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"驻关将领营帐"+NOR+"");
    set_long("    这里是驻关将领处理日常事物的地方，遇到敌军进犯，就成了讨论军
机，运筹帷幄的地方。
\n\n");
    set_exits( ([
        "east" :  __DIR__+"hangu_camp.c",
    ]) );
}


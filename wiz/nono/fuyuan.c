#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

private mapping exits;

void bind_exit(string direction, object room, int both);
void setexits();


void setup()
{
    set_area("nono_room");
    set_light(50);
    set_brief(""+HIW+"府院"+NOR+"");
    set_long(
"你走进大院，迎面是一个假山水池，池上摆着一块奇形怪状的石头，据说是当年
花石纲的遗石。水池的两旁种满了花草。一条长廊走道通往後院，几个家丁正在扫
地。");


    set_exits( (["enter" : "/wiz/nono/workroom.c",
                 "east" : "/wiz/nono/huayuan.c",
"out" : "/wiz/nono/gate.c",
                 ]) );              
}



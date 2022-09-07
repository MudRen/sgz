// 黄土大道 by lcm
// cc_htdd.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"黄土大道"+NOR+"");
    set_long("
    此处乃是通往陈仓道口的大道。相信大家还记得当年韩信“暗度
陈仓”之计，陈仓乃兵家要地，不可不守。此去往东走可到达咸阳。
\n\n");
    set_exits( ([
        "west" :  __DIR__+"cc_xd1.c",
        "east" :  __DIR__+"xianyang.c",
    ]) );
}

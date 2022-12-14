// 三军大寨 by lcm
// cc_sjds.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"三军大寨"+NOR+"");
    set_long("
    这里是守卫陈仓道口大军的大本营。镇守陈仓的将军正在督促士
兵们筑起坚固的城墙。城的四周也有军士在挖沟。看来这里不久将会
暴发一场战争，关系也非常重大。将军因领导有方，士兵们个个都士
气高昂，已准备死守此地。\n\n");
    set_exits( ([
        "west" :  __DIR__+"cc_xd.c",
        "enter" :  __DIR__+"cc_yst.c",
        "east" :  __DIR__+"cc_xd1.c",
    ]) );
}

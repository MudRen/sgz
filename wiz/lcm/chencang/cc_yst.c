// 陈仓议事厅 by lcm
// cc_yst.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"议事厅"+NOR+"");
    set_long("
    这里是守军主将处理军务的地方。其实主将大多数时间并不是在
处理文件，而是在操练军队，让士兵熟悉迎战敌人的策略。\n\n");
    set_exits( ([
        "out" :  __DIR__+"cc_sjds.c",
    ]) );
}

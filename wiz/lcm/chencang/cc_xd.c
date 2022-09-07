// 陈仓小道 by lcm
// cc_xd.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"小道"+NOR+"");
    set_long("
    此处依山傍水，兵队可在此下寨，筑起重城，以拒守敌人。据说
几千精兵也可抵得住几十万敌兵。\n\n");
    set_exits( ([
        "west" :  __DIR__+"cc_dk.c",
        "east" :  __DIR__+"cc_sjds.c",
    ]) );
}

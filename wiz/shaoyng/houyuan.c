#include <mudlib.h>
#include <ansi.h>
inherit ROOM;
void setup()
{
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"猪香庄"+HIY+"桃树林后院"+NOR+"");
    set_long("
后院里的树上，忽然结出了满树又甜又大的桃子，摘下来足足
可以装几十篓，卖出去应可卖二三十两银子。
伯约看到你走来了，无可奈何的说到：“我那二弟出门去了。
您还是请以后再来吧。”\n\n");
    set_exits ((["out"       :  "/wiz/shaoyng/workroom.c",
                 "xiliang"   :  "/sgdomain/area/cities/xiliang/xiliang_M.c"
                ]) );
    set_hidden_exits("xiliang");
    set_objects (([ "/wiz/shaoyng/npc/jiangwei.c" : 1 ]));
}                             



// 狄道道口
// dd_dkx.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"狄道道口"+NOR+"");
    set_long("  这里是狄道的入口。虽然狭小，但是仍然可以通行千军万马。
由此是通往天水的必经之路。前面是长长的弯路，据说如果是
黑夜进入的话是出不来的。\n\n");
    set_exits( ([
        "west" :  __DIR__+"xiliang.c",
        "east" :  __DIR__+"dd_wl.c",
    ]) );
}

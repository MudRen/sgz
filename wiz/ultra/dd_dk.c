// 狄道道口
// dd_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"狄道道口"+NOR+"");
    set_long("  这里是狄道的入口。虽然狭小，但是仍然可以通行千军万马。
由此是通往西凉的必经之路。隐约可以看到前面有个山头，如果
在那里埋伏奇兵的话，可能会造成重大的损伤。\n\n");
    set_exits( ([
        "north" :  __DIR__+"dd_xst.c",
        "south" :  __DIR__+"tianshui.c",
    ]) );
}



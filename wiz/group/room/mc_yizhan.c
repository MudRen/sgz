////by ljty April,6 1998
// 驿站,mc_center.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
set_area("mc_area");
    set_light(1);
    set_brief(""+YEL+"驿站"+NOR+"");
    set_long("    这里是渑池的驿站，一个身穿布衣的青年人站在台前，站后
传来一阵一阵的马嘶声。你如果想去那里的话，可以问问马夫。\n\n");
    set_exits( ([
        "northeast" : __DIR__+"mc_lk1.c",
    ]) );
   set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );

}

#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief("--小东西的厨房--");
    set_long(
"窗明几净的厨房
冰箱，煤气灶，......桌上搁着刚洗完的菜，砧板上正切着一些
肉丝。等一会就要开饭啦...... :)
");
    set_exits( ([
        "out" :  "/wiz/benben/workroom.c"
    ]) );
set_objects( ([ "/wiz/benben/NPC/benben.c" : 1 ]) );
}                             

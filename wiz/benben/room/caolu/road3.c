//  小道3 road3.c
// made by benben
// cl_road3.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"树林"+NOR+"");
    set_long("    眼前是一个树林，树木稀疏，错落有致。忽然听到林深之处有人
声，你急忙穿入林中，侧耳倾听，原来是樵夫的歌声。\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_bridge.c",
        "north" :  __DIR__+"cl_road2.c",
    ]) );
set_objects( ([ "/wiz/benben/NPC/qiaof.c" : 1 ]) );
}

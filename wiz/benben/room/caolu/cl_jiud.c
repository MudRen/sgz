//  酒店 jiud.c
// made by benben
// cl_jiud.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"乡村酒店"+NOR+"");
    set_long("    酒店里两人对饮，上座的白面长须，乃是颖州石广元，下座的清
奇古貌，乃是汝南孟公威。二人都是孔明的朋友，想来是访客途中，饮酒歇息吧。\n\n");
    set_exits( ([
        "south" :  __DIR__+"cl_road4.c",
    ]) );
// set_objects( ([ "/wiz/benben/NPC/shi.c" : 1 ]) );^M
// set_objects( ([ "/wiz/benben/NPC/meng.c" : 1 ]) );^M
}

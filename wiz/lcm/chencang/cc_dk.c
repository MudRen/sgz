// 陈仓道口 by lcm
// cc_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"陈仓道口"+NOR+"");
    set_long("
    陈仓道口乃是兵家要地，是蜀魏必争之地。因为蜀地多是山川，
蜀兵若能争得陈仓，将使运粮较为方便。离此处西北是街亭，也是另
一处要地。\n\n");
    set_exits( ([
        "north" :  __DIR__+"qinchuan.c",
        "east" :  __DIR__+"cc_xd.c",
    ]) );
}

// 狄道弯路
// dd_wl.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"弯路"+NOR+"");
    set_long("  天上有九百九十九个星，狄道有九百九十九个弯。
弯不尽长长流水，看不够矮矮灌木。这一个一个的弯，
宛如战斗的艰辛，未来的路。豪情在心，利刃在胸!\n\n");
    set_exits( ([
        "southeast" :  __DIR__+"dd_dl.c",
        "northeast" :  __DIR__+"dd_xy.c",
        "west" :  __DIR__+"dd_dkx.c",
    ]) );
}

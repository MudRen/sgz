//  城西巷
// ly_chengxx.c decribed by ljty on 1.8.1998
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ly_area");
    set_light(50);
    set_brief(""+YEL+"城西巷"+NOR+"");
    set_long("    这是洛阳城西的一条小巷子，龙蛇混杂。西面是一家赌场，人们
到这都会快步离开，惟恐输红了眼的赌徒抢劫钱财。
\n\n");
    set_exits( ([
        "north" :  __DIR__+"ly_xdj3.c",
        "south" :  __DIR__+"ly_chengxx2.c",
        "west" :  __DIR__+"ly_duc.c",
    ]) );
}

// 街亭粮草屯积处
// jt_lcao.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"粮草屯积处"+NOR+"");
    set_long("   街亭驻兵屯积粮草的地方，有兵士守卫，如果没有粮草，数万大军就只有束手就擒了。\n\n");
    set_exits( ([
        "west" :  __DIR__+"jt_area.c",
    ]) );
}



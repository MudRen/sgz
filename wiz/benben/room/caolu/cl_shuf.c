//  �鷿
// cl_shuf.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"�鷿"+NOR+"");
    set_long("    �����������鷿\n\n");
    set_exits( ([
        "east" :  __DIR__+"cl_zht.c",
    ]) );
}

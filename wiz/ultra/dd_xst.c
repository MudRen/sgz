// 狄道小山头
// dd_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"小山头"+NOR+"");
    set_long("  一片阴凉的小地方，正好可以避避太阳。走了这么久在这里
小作休憩真是一件快事。不过想起了还有好多事要做，你不禁
振作起来，加快了脚步。\n\n");
    set_exits( ([
        "north" :  __DIR__+"dd_dl.c",
        "south" :  __DIR__+"dd_dk.c",
    ]) );
}


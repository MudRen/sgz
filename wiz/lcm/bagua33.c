#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit "/wiz/lcm/baguaroom.c";



void setup()
{
    ::setup();
    bind_exit("up", "/wiz/lcm/lcmroom", 0);
    setexits();
//    set_exits( (["up" : "/wiz/lcm/lcmroom.c",
//                ]) );              
}


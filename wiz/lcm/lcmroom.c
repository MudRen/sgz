#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup()
{
    set_area("lcm_room");
    set_light(50);
    set_brief(""+HIB+"姜维"+NOR+"的家");
    set_long(
"\n姜维是个简单的人。房间也没有什么装置，
只一张桌子与椅子。\n
桌上放着两本书，一本是"+HIY+"“三国演义”"+
NOR+"，另一本是"+HIY+"“水浒传”"+NOR+"。");
    set_exits( (["out" : FROOMPATH+"vzhu_lin.c", 
                 "up" : "/wiz/liz/workroom.c",
                 "down" : "/wiz/lcm/bagua33.c",
                 ]) );              
}

//  ����
// cl_mdoor.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"����"+NOR+"");
    set_long("���������\n\n");
    set_exits( ([
        "north" :  __DIR__+"cl_qt.c",
        "south" :  __DIR__+"cl_door.c",
    ]) );
}

//  С· road2.c
// made by benben
// cl_road2.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"С·"+NOR+"");
    set_long("    ת�����֣���Ȼ����һ�����ĵ�é®������ɽ���£�����������
�������ţ����µ�С·ͨ�����\n\n");
    set_exits( ([
        "north" :  __DIR__+"cl_door.c",
        "south" :  __DIR__+"cl_road3.c",
    ]) );
}

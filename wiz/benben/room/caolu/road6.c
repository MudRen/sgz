//  С��6 road6.c
// made by benben
// cl_road6.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"С��"+NOR+"");
    set_long("    ����20��ؾ����������ˣ�������һ����ɽ����´������и�
�����ӡ�\n\n");
    set_exits( ([
        "west" :  __DIR__+"xiangyang.c",
        "east" :  __DIR__+"cl_road5.c",
    ]) );
}

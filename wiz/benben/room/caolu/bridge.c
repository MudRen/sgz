//  С�� bridge.c
// made by benben
// cl_bridge.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"С��"+NOR+"");
    set_long("    ����Ϫˮ��ˮ���������������Ͽ��ٴ��Ҷ��¡�\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_road4.c",
        "east" :  __DIR__+"cl_road3.c",
    ]) );
}

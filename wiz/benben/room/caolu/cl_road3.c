//  С��3 road3.c
// made by benben
// cl_road3.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"����"+NOR+"");
    set_long("    ��ǰ��һ�����֣���ľϡ�裬�������¡���Ȼ��������֮������
�����㼱æ�������У����������ԭ�����Է�ĸ�����\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_bridge.c",
        "north" :  __DIR__+"cl_road2.c",
    ]) );
set_objects( ([ "/wiz/benben/NPC/qiaof.c" : 1 ]) );
}

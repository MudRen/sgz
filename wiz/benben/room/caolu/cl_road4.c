//  С�� road4.c
// made by benben
// cl_road4.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"С��"+NOR+"");
    set_long("    ң�������ԣ���Ȼ�徰�쳣����Զ������С�ţ�·���Ǹ�С�Ƶ꣬
����������������裬������ʲô�������ˡ�\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_road5.c",
        "east" :  __DIR__+"cl_bridge.c",
        "north" :  __DIR__+"cl_jiud.c",
    ]) );
}

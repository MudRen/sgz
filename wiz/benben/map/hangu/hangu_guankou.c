//  ���ȹ� by benben
// hangu_guankou.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"���ȹ�"+NOR+"");
    set_long("    �����Ǻ��ȹأ����˹ؾ���μˮ����ͨ�������ıؾ�֮�ء�
\n\n");
    set_exits( ([
        "north" :  __DIR__+"hangu_camp.c",
        "east" :  __DIR__+"hangu_lane.c",
    ]) );
}


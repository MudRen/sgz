// riverarea.c "С��"
#include <mudlib.h>
#include <ansi.h>
inherit WATER_ROOM;

void setup(){
    set_area("huayin");
    set_light(2);
    set_brief(YEL+"С��"+NOR);
    set_long("\nһ�������С�ӡ�\n\n");

    set_exits( ([
        "north" : __DIR__+"southopen",
    ]) );

    set_enter_msg("south", "$NС��������߽�С�ӡ�\n");
    set_exit_msg("north", "$N��С�������ϰ�ȥ��\n");
    set_objects( ([
        "/sgdomain/job/fishing/pound" : 1,
       "/sgdomain/job/fishing/yufu" : 1,
	]) );
}

// �²�С�� by lcm
// cc_xd.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"С��"+NOR+"");
    set_long("
    �˴���ɽ��ˮ�����ӿ��ڴ���կ�������سǣ��Ծ��ص��ˡ���˵
��ǧ����Ҳ�ɵֵ�ס��ʮ��б���\n\n");
    set_exits( ([
        "west" :  __DIR__+"cc_dk.c",
        "east" :  __DIR__+"cc_sjds.c",
    ]) );
}

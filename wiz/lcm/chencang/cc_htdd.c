// ������� by lcm
// cc_htdd.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"�������"+NOR+"");
    set_long("
    �˴�����ͨ���²ֵ��ڵĴ�������Ŵ�һ��ǵõ��꺫�š�����
�²֡�֮�ƣ��²��˱���Ҫ�أ����ɲ��ء���ȥ�����߿ɵ���������
\n\n");
    set_exits( ([
        "west" :  __DIR__+"cc_xd1.c",
        "east" :  __DIR__+"xianyang.c",
    ]) );
}

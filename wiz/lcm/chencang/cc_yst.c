// �²������� by lcm
// cc_yst.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"������"+NOR+"");
    set_long("
    �������ؾ������������ĵط�����ʵ���������ʱ�䲢������
�����ļ��������ڲ������ӣ���ʿ����Ϥӭս���˵Ĳ��ԡ�\n\n");
    set_exits( ([
        "out" :  __DIR__+"cc_sjds.c",
    ]) );
}

// ������կ by lcm
// cc_sjds.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"������կ"+NOR+"");
    set_long("
    �����������²ֵ��ڴ���Ĵ�Ӫ�����س²ֵĽ������ڶ���ʿ
���������̵ĳ�ǽ���ǵ�����Ҳ�о�ʿ���ڹ����������ﲻ�ý���
����һ��ս������ϵҲ�ǳ��ش󡣽������쵼�з���ʿ���Ǹ�����ʿ
���߰�����׼�����ش˵ء�\n\n");
    set_exits( ([
        "west" :  __DIR__+"cc_xd.c",
        "enter" :  __DIR__+"cc_yst.c",
        "east" :  __DIR__+"cc_xd1.c",
    ]) );
}

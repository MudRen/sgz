// �²ֵ��� by lcm
// cc_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("chencang");
    set_light(50);
    set_brief(""+YEL+"�²ֵ���"+NOR+"");
    set_long("
    �²ֵ������Ǳ���Ҫ�أ�����κ����֮�ء���Ϊ��ض���ɽ����
����������ó²֣���ʹ������Ϊ���㡣��˴������ǽ�ͤ��Ҳ����
һ��Ҫ�ء�\n\n");
    set_exits( ([
        "north" :  __DIR__+"qinchuan.c",
        "east" :  __DIR__+"cc_xd.c",
    ]) );
}

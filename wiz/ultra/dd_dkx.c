// �ҵ�����
// dd_dkx.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"�ҵ�����"+NOR+"");
    set_long("  �����ǵҵ�����ڡ���Ȼ��С��������Ȼ����ͨ��ǧ������
�ɴ���ͨ����ˮ�ıؾ�֮·��ǰ���ǳ�������·����˵�����
��ҹ����Ļ��ǳ������ġ�\n\n");
    set_exits( ([
        "west" :  __DIR__+"xiliang.c",
        "east" :  __DIR__+"dd_wl.c",
    ]) );
}

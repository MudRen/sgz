// �ҵ�����
// dd_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"�ҵ�����"+NOR+"");
    set_long("  �����ǵҵ�����ڡ���Ȼ��С��������Ȼ����ͨ��ǧ������
�ɴ���ͨ�������ıؾ�֮·����Լ���Կ���ǰ���и�ɽͷ�����
�������������Ļ������ܻ�����ش�����ˡ�\n\n");
    set_exits( ([
        "north" :  __DIR__+"dd_xst.c",
        "south" :  __DIR__+"tianshui.c",
    ]) );
}



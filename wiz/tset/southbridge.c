// southbridge.c "ɽ��"
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("southbridge");
    set_light(0);
    set_brief(YEL+"ɽ��"+NOR);
    set_long("
��������ߵ���ߡ�ѽ��ԭ�������и�Сɽ�أ��㲻�������Ķ���
������һ��С�ӣ����Դ�����(bridge)�߹�ȥ��
\n\n");
    set_objects( ([
        __DIR__"bridge" : 1,
                    ]) );

    set_default_exit("�����߲�ͨҮ��\n");

    set_exits( ([
        "south" : __DIR__ "cave",
    ]) );
}


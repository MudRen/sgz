// �ҵ�Сɽͷ
// dd_dk.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"Сɽͷ"+NOR+"");
    set_long("  һƬ������С�ط������ÿ��Աܱ�̫����������ô��������
С���������һ�����¡����������˻��кö���Ҫ�����㲻��
�����������ӿ��˽Ų���\n\n");
    set_exits( ([
        "north" :  __DIR__+"dd_dl.c",
        "south" :  __DIR__+"dd_dk.c",
    ]) );
}


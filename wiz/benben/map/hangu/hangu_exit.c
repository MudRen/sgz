//  ���ȹ� by benben
// hangu_exit.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"���ȹ�"+NOR+"");
    set_long("    �����Ǻ��ȹأ����������أ�������μˮ�����˹��������Ǻ�ũ��
\n\n");
    set_exits( ([
        "south" :  __DIR__+"hangu_camp.c",
        "north" :  __DIR__+"weishui.c",
    ]) );
}


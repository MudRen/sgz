//  ���ȹ� by benben
// hangu_lane.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"ͨ�����ȹص�С��"+NOR+"");
    set_long("    һ��С������������������ũ�ǣ��������Ǻ��ȹ��ˡ�
\n\n");
    set_exits( ([
        "west" :  __DIR__+"hangu_guankou.c",
        "east" :  __DIR__+"    ?",
    ]) );
}


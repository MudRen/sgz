//  ���ȹ� by benben
// hangu_meetingroom.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"פ�ؽ���Ӫ��"+NOR+"");
    set_long("    ������פ�ؽ��촦���ճ�����ĵط��������о��������ͳ������۾�
�����˳��ᢵĵط���
\n\n");
    set_exits( ([
        "east" :  __DIR__+"hangu_camp.c",
    ]) );
}


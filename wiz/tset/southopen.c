// southopen.c "�ϴ��"
#include <mudlib.h>
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
    set_area("huayin");
    set_light(100);
    set_brief(YEL+"�ϴ��"+NOR);
    set_long("
������һ����ڣ�������һ��СС�Ĵ�ׯ��һ��С��ͯ���ڷ�ţ��
�ϱ���һ��С�ӣ����Դ�����(bridge)�߹�ȥ��
\n\n");

    set_exits( ([
        "north" : FROOMPATH+"vnangxiao_hang",  // modified by fire Dec 11, 97
        "south" : __DIR__+"riverarea",
    ]) );

    set_exit_msg("south", "$NС��������߽�С�ӡ�\n");
    set_enter_msg("north", "$N��С�������ϰ�����\n"); 

    set_objects( ([
        __DIR__"bridge" : 1,
        __DIR__+"mutong" :  1,
        __DIR__+"niu" : 1,
                    ]) ); 
}
 

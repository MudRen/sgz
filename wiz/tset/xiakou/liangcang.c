//  liangcang.c
//  �Ŀ�����
//  created by tset 1/23/98
//  last updated by tset 1/23/98
                      
#include <mudlib.h>

inherit INDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("����");
        set_long("
�������Ŀڵľ������֣��ֿ��ſ��������ػ�����Щʿ���������
����������������Ҳ�е�ʿ�������������
\n\n");

  set_exits( ([
        "south" : __DIR__"xiakoue",
                ]) );
        
}

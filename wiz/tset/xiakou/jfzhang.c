//  jfzhang.c
//  �Ŀ��˷�
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;

void setup(){
        object door;
        set_area("xiakoujf");
        set_light(20);
        set_brief("�˷�");
        set_long("
һλ�˷�����������߿ž���ش������̣������������������
�·�ʲô��û������
\n\n");

  set_exits( ([
        "south" : __DIR__"jiangfu"
                ]) );
}

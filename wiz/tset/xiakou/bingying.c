//  bingying.c
//  �Ŀڱ�Ӫ
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("��Ӫ");
        set_long("
��Ӫ����������ֳֵ�ǹ����Уξ�ļල�¿̿�������ſ���ʿ��
�����������㣬˵�����������������
\n\n");

  set_exits( ([
        "east"  : __DIR__"xiakoudjc",
        "north" : __DIR__"xiakoue",  
                ]) );
                
}

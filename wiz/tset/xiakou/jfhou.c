//  jfhou.c
//  �Ŀں�
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;

void setup(){
        object door;
        set_area("xiakoujf");
        set_light(20);
        set_brief("��");
        set_long("
���м���Ѿ�����ںͷ���С�������߻һ���������߽�������
��ææ����ʰ�������ߵ�һ��ȥ�ˡ�
\n\n");

  set_exits( ([
        "east" : __DIR__"jiangfu"
                ]) );
                
  set_objects( ([
         __DIR__"obj/jf_door" : ({ "east" }),
                ]) );
                
  set_default_exit( "��ǽ��������������·�ĺá�\n");
  door = present( "door");
  if( !door->query_closed())
  door->do_on_open();
}

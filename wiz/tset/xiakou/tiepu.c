//  tiepu.c
//  �Ŀ�����
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;
inherit "/sgdomain/modules/m_store.c";

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("����");
        set_long("
�����﹤������ͷ�󺹵ش��Ʊ���������ǽ�Ƿ��˺�Щ�Ѿ�������
�ϵ����������������������æ������С����æ���͹����Լ�����
��(list)�ɡ���
\n\n");

  set_exits( ([
        "west" : __DIR__"xiakous"
                ]) );
                
  add_object( __DIR__"obj/jia.c" );
}
 

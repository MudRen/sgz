//���ϻ�� by benben
#include <mudlib.h>
#include <setbit.h>
inherit COMPLEX_CONTAINER;
inherit M_GETTABLE;
inherit M_LOCKABLE;
inherit M_OPENABLE;
void setup(){	
::mudlib_setup();
  set_in_room_desc("���ϻ��");
  set_adj( "һ�����ɫ��" );
  set_id( "box","ϻ��", );
  set_long("    һ�����ɫСϻ���ý������š�\n");
  set_relations("in");
  set_max_capacity(MEDIUM);
}





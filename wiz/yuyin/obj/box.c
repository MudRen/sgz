//���ϻ�� by benben
#include <mudlib.h>
#include <setbit.h>
#include <sanguo.h>
inherit COMPLEX_CONTAINER;
inherit M_GETTABLE;
inherit M_LOCKABLE;
inherit M_OPENABLE;
void setup(){   
  object ob1,ob2;
  set_in_room_desc("һ��С�ɵ��Ǻ�(box)��");
  set_adj( "С�ɵ�" );
  set_id( "box","�Ǻ�", );
  set_long("һ��С�ɵ��ǺУ�����д�ţ�������ǣ����ݽ�����\n");
  set_relations("in");
  set_max_capacity(SMALL*2);
  ob1=new(FOBJPATH+"candy");
  ob1->move(this_object());
  ob2=new(FOBJPATH+"candy");
  ob2->move(this_object());
}

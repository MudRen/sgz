// created by ice on Jul 21 1999
#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_GETTABLE;
void setup()
{
	call_out("dest",100);
  set_id("oxhead","%^RED%^ţͷ"+NOR);
  set_long("һֻ������Ʒ��ţͷ��");
  set_in_room_desc("һֻ������Ʒ��"+RED+"ţͷ"+NOR+"���˶������ط��������");
     set_can_drop(0);
     set_can_drop("��Ʒ���ҵ����Ҷ���\n");
     set_can_give(0);
  set_gettable(0);
  set_gettable("ιιι������Ĺ�ƷҲҪ�ã�������Ǵ��\n");
  set_unit("ֻ");
}
void dest()
{
       write("��ͻȻ�����������һֻ�֣������Ӽ�����ʢ��%^RED%^ţͷ%^RESET%^һ�Ѿ�ץ���ص���ȥ�ˡ�\n");
       destruct(this_object());
}

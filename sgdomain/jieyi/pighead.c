// created by ice on Jul 21 1999
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
void setup()
{
  set_id("pighead", HIY+"��ͷ"+NOR);
  set_long("һֻ������Ʒ����ͷ��");
  set_in_room_desc("һֻ������Ʒ��"+HIY+"��ͷ"+NOR+"���˶������ط��������");
     set_can_drop(0);
     set_can_drop("��Ʒ���ҵ����Ҷ���\n");
     set_can_give(0);
  set_gettable(0);
  set_gettable("ιιι������Ĺ�ƷҲҪ�ã�������Ǵ��\n");
  set_unit("ֻ");
	call_out("dest",100);
}
void dest()
{
       write("��ͻȻ�����������һֻ�֣������Ӽ�����ʢ��%^H_YELLOW%^��ͷ%^RESET%^һ�Ѿ�ץ���ص���ȥ�ˡ�\n");
       destruct(this_object());
}

//�������� by benben
#include <mudlib.h>
#include <setbit.h>
inherit OBJ;
inherit M_GETTABLE;
void setup(){	
::mudlib_setup();
  set_in_room_desc("��������");
  set_unit( "��" );
  set_id( "yuxi","����",  "jade","��������");
  set_long("    ���Ǻ��ҵĴ���֮������Բ�Ĵ磬����������Ŧ����ȱһ�ǣ���
�ƽ���֮������׭�İ����ƣ��������죬�����������ഫ���Ǻ����
�Ƴɵġ�\n");
}

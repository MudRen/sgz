// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_DIGGABLE;
inherit M_INPUT;

void setup()
{
  set_adj("ɳ����");
  set_unit("��");
  set_id("castle", "�Ǳ�", "sculpture");
  set_in_room_desc("����ǰ��һ����ɳ���ɵĳǱ���");
  set_long("����ɳ��׼��һλ������ŵĽ������������¥��Χǽ�����ʮ�־�ϸ��"
           "����㲻����ɳ����㽫������Ϊ����ɳ�����ɵġ�������ָ���˴���"
           "��û�д���������ľ���ʯ����һ����");
  set_size(TOO_LARGE);
}

void do_enter()
{
  write("�㲻̫���ܽ�ȥ����Ϊ����û���š�\n");
}


mixed direct_enter_obj()
{
  return 1;
}

void dig(object o)
{
  this_body()->simple_action("$N���������Ǳ���ȴ����������ʯһ����Ӳ��");
}

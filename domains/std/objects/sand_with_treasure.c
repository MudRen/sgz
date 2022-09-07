// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <size.h>

inherit OBJ;
inherit M_DIGGABLE;
inherit M_INPUT;  // Required for M_DIGGABLE.

int number_times_dug = 0;
object  my_hole;

void setup()
{
  set_id("beach","ɳ̲", "sand");
  set_unit("Ƭ");
  set_attached(1);
  set_long("����кܶ�ɳ��\n");
  set_size(TOO_LARGE);
}


void dig(object o)
{
  switch(number_times_dug++)
    {
    case 0:
      my_hole = new("/domains/std/objects/hole");
      my_hole->move(environment(this_object()));
      this_body()->simple_action("$N������ɳ�����ڶ���һ�����˺ü��¡�");
      my_hole->change_desc("ɳ������һ��С����");
      break;
    case 1:
      my_hole->set_in_room_desc("ɳ������һ������");
    case 2:
      this_body()->simple_action("$N�ְѶ�������һЩ��");
      break;
    case 3:
      my_hole->change_desc("ɳ������һ���󶴡�");
      my_hole->change_max_capacity(VERY_LARGE);
    case 4:
      this_body()->simple_action("$N�����Ѷ������ڡ�");
      break;
    case 5:
      my_hole->change_desc("ɳ���ϳ�����һ���ܴ�Ķ���");
      my_hole->change_max_capacity(VERY_LARGE*2);
    case 6:
      this_body()->simple_action("$N�ְѶ�������һЩ��");
      break;
    case 7:
      this_body()->simple_action("$N���������˼��£�������һ���䱦�䣡");
      QUEST_D->grant_points(this_body(), "pirate");
      break;
    case 8:
      this_body()->simple_action("$N�����Ѷ������ڡ�");
      break;
    case 9:
    case 10:
      this_body()->simple_action("$N�ְѶ�������һЩ��");
      break;
    default:
      this_body()->simple_action("$N�����ڶ�����û��ʲô��Ч���Ǹ����ֱ������µ�ɳ��������һЩ��\n"
                                 "���еĶ����������ˡ�");
      break;
                                
    }
}

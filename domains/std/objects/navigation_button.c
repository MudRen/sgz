// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;

void setup() {
    
    set_id("button", "��ť");
    set_long("������ť����������������·�ϵ�ͨ���ġ�\n");
    set_in_room_desc("�㿴������ͨ��һ�Ե�ǽ�ϣ���һ����ť��");
    set_size(VERY_SMALL);
}

int press(string n)
{
  this_body()->simple_action("$N����ǽ�ϵİ�ť��");
  environment(this_object())->open_passage();
  return 1;
}

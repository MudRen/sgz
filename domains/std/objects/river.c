// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;

void setup()
{
  set_unit("��");
  set_id("river", "С��", "water");
  set_long(
"һ��С���ɶ�������������������ȥ���������Ҫ�ʹ���ȥ�������Ǹ����⡣\n");
  set_size(TOO_LARGE);
set_flag(ATTACHED);
}

mixed swim()
{

  this_body()->simple_action("$N�ں�������һ�����\n"
                             "��$n���ϰ�ʱ�����غ�Ȼ����һ�¡�");
  call_out((: environment(this_object())->open_passage() :), 3);
  return 1;
}

mixed wade()
{
  this_body()->simple_action("$N�ں�������һ���ˮ��\n"
                             "��$n�ϰ�ʱ�����غ�Ȼ����һ�¡�");
  call_out((: environment(this_object())->open_passage() :), 3);
  return 1;
}



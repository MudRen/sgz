// Updated by tset on 2 Feb 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
   
void setup()
{  
  set_attached(1);
  set_unit("��");
  set_light(10);
  set_id("bridge","С��");
  set_long("һ��С�ź���ں��ϡ�");
}
   
void cross()
{
  if(environment(this_body())->get_area() == "huayin")
  {
    write("�㳯��������С�š�\n");
    this_body()->move(__DIR__"southbridge");
    this_body()->do_game_command("look");
    this_body()->other_action("$N��������Ŷ�ȥ�ˣ��뿪��������ߡ�\n");
  }
  else if(environment(this_body())->get_area() == "southbridge")
  {
    write("�㳯��������С�š�\n");
    this_body()->move(__DIR__"southopen");
    this_body()->do_game_command("look");
    this_body()->other_action("$N��������Ŷ�ȥ�ˣ��뿪��������ߡ�\n");
  }
  else
  {   
    write("������С�ţ�����֪�������Ƕ��߲Ŷԣ����������˻�����\n");
    this_body()->other_action("$N�������ȥ�ˣ�����һ�����ת�����ˡ�\n");
  }
}

// Updated by tset on 2 Feb 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
   
void setup()
{  
  set_attached(1);
  set_unit("��");
  set_light(10);
  set_id("bridge","Сľ��");
  set_long("����ȥ���ʧ�޵�Сľ�ţ��紵��ʱ����һ����ѽ��ѽ��������������������Щ���ġ�\n
��������� (cross bridge)��");
}
   
void cross()
{
  if(environment(this_body())->get_area() == "eastside")
  {
    write("\n��̧��������Сľ�ţ�һ��һ���ĵ�����Ų�š�\n\n");
    this_body()->move(__DIR__"ground");
    this_body()->do_game_command("look");
    this_body()->other_action("\n$NС��������߹���Сľ�ţ����˶԰���Сľ��ǰ��\n\n");
  }
  else if(environment(this_body())->get_area() == "westside")
  {
    write("\n����ԥ������������Сľ�ţ�����ֱ�����\n\n");
    this_body()->move(__DIR__"plain");
    this_body()->do_game_command("look");
    this_body()->other_action("\n$N��ͷ����������һ�ۣ��ٳ����ɹ����š�\n\n");
  }
  else
  {   
    write("\n����Сľ���ϣ�ֱ���ý���һ������������ȥ����æ�����˻�����\n\n");
    this_body()->other_action("\n$N�ƺ���Ҫ���ţ���֪Ϊʲô�����˻�����\n\n");
  }
}

//by chun 
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit OBJ;
void setup()
{
  set_id("roses", HIR+"õ��"+NOR);
  set_long("һ�ؽ��޵�õ�壬��������д̵�õ���㻹�ǲ�Ҫ�ɰ�(zhe)��\n");
  set_size(VERY_SMALL);
  set_in_room_desc("һ�ؽ��޵�"+HIR+"õ��"+NOR+"(roses)");
  }

int smell() {
  write("��õ��ɢ�������˵����㡣\n");
  return 1;
}

int zhe(string n) {
  object o_rose;
  this_body()->simple_action("$N�̲�סժ��һ��õ�塣\n");
  if (!random(5)) {
  	this_body()->simple_action("$N��С����õ������һ�£����ۡ�\n");
  	this_body()->set_cur_hp(0);
  }
  o_rose=new("/wiz/chun/rose.c");
  o_rose->get();
  o_rose->move(this_body());
  return 1;
 }
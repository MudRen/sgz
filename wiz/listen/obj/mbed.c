// created by fire on Jan 19 1998
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit FURNITURE;
inherit M_VALUE;
void setup()
{
  set_id("mbed", "%^RED%^˫�˴�%^RESET%^");
  set_unit("��");
  set_value(3000000);
  set_in_room_desc("һ�����ʵ�%^RED%^˫�˴�%^RESET%^(mbed)");
  set_get_on_msg("");
  set_get_off_msg("$N��������ش�%^RED%^˫�˴�%^RESET%^��վ������ȴ��Ȼ�ڻ�ζ�ղŵ�����\n");
  set_long("����һ��%^H_RED%^��ȼѩ%^RESET%^��%^H_GREEN%^������Ȼ%^RESET%^�Ľ��ϲ����\n");
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*2, "on");
}
// Unlike most furniture, you can lie on a bed.  We'll assume you mean sit
// on the bed here, but you can do what you want...
int direct_lie_on_obj()
{
  return 1;
}
int lie()
{
  return sit();
}
int mount_it_already()
{
  string stat;
  if(environment(this_body()) == this_object())
    {
      write("���Ѿ����ڴ�����\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N�������������%^RED%^˫�˴�%^RESET%^�ϣ����ĵ�ϣ�����������г��֡�\n");
  foreach (object ob2 in all_inventory(this_body())) 
  {
		
        	stat=ob2-> ob_state() ;
		if(stringp(stat))
		{
			ob2->do_remove();
		}
  }
  return 1;
}
int is_bed()
{
	return 1;
}

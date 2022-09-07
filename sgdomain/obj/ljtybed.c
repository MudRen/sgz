// created by fire on Jan 19 1998
#include <ansi.h>
inherit FURNITURE;
void setup()
{
  set_id("bed", HIG+"˫�˴�"+NOR);
  set_unit("��");
  set_in_room_desc("˫�˴�(bed)");
  set_get_on_msg("");
  set_get_off_msg("$N�Ӵ���վ������\n");
  set_long("�����˼�����ƽ����Ϣ�õĴ���");
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
      write("���Ѿ����ڴ����ˡ�\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N�����·����������������"+short()+"�ϡ�\n");
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

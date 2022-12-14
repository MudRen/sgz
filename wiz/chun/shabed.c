// created by fire on Jan 19 1998
#include <ansi.h>
inherit FURNITURE;
void setup()
{
  set_id("shabed",HIG+"青纱帐"+NOR);
  set_unit("张");
  set_in_room_desc("一张幽幽的"+HIG+"青纱帐"+NOR+"(shabed)");
  set_get_on_msg("$N轻轻的坐上青纱帐");
  set_get_off_msg("$N从床上站起来。\n");
  set_long("这是一张幽幽的青纱帐．\n");
  set_exits( ([
        "out": __DIR__+"room/dream.c",
  ]) );
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*4, "on");
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
      write("你已经躺在床上了。\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N轻轻躺上"+short()+"。\n");
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
int smell()
{
  write("青纱帐散发着一阵醉人的幽香\n");
  return 1;
}

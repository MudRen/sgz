//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_VALUE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("֦");
set_value(9999);
set_id("rose", HIR+"õ��"+NOR);
set_long("һ֦���޵�"+HIR+"õ��"+NOR+"(rose)");
set_in_room_desc("һ֦"+HIR+"��õ��"+NOR+"(rose)");
set_gettable(1);
set_slot(BREST);
//set_wearmsg("$N����ǰ����һ֦"+HIR+"��õ��"+NOR+"���Եø��ӽ��޶��ˡ�\n");
set_removemsg("$NС������ؽ�"+HIR+"��õ��"+NOR+"����ǰȡ������\n");
}
int smell() {
  object who;
  who = environment(this_object());
  this_body()->set_cur_hp(0);
  write("���õ����Ϥ����ζʹ�㲻�ɵ�������һ���ˣ�����\n");
  write("��ֻ��һ����ʹ��������˹�ȥ��\n");
  return 1;
}

void do_wear() {
  object who;
  who=owner(this_object());
  foreach (object ob2 in all_inventory(who)) 
  {
        
  	if ((ob2->ob_state()==BREST))
        {
                write("���Ѿ�������ͬ��װ���ˡ�\n");
                return;
        }
  }   
  who->simple_action("$N����ǰ����һ֦"+HIR+"��õ��"+NOR+"û�뵽õ�������������$N�����ѣ�\n");
  who->set_cur_hp(0);
}

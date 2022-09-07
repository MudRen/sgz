#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
    
private *name_list_take_horse =({ });
void setup() 
{
  object jia;
  
  set_name("mafu", "���");
  set_proper_name("���");
  set_gender(1);
  set_age(38);
  set_in_room_desc("���(mafu)");
  set_long("����λ��ʵ�ͽ��������ͷ�󺹣���������մ���˲���м��\n");

  jia = new("/sgdomain/obj/cloth/torso/buyi.c");
  jia->move(this_object());
  jia->do_wear();
  
  add_question("horse","horse");
}
void special_answer(object who,string matt)
{
  string p_id;
  int p_shenwang;
  object ob;
  object user_horse;
  
  switch(matt)
    {
    case "horse":
        p_id=this_body()->query_userid();
	if(member_array(p_id,name_list_take_horse) != -1)
	  {
	    this_object()->targetted_action(
"$N��$t˵���������Ѿ�Ҫ��һƥ�ˣ���ô��Ҫ�����ƳԽ������ܶ������\n",who);
	    return;
	  }
	else
	  {
	    this_object()->targetted_action(
 "$N��$t˵�����������Եȣ�С����͸���ǣ��������\n����һ�ᣬ$Nǣ��һƥ����\
��������$t�����ϣ���$t˵����������������ˡ���\n",who);
	    
	    name_list_take_horse += ({ p_id });
	    p_shenwang = who->query_shengwang_int();
	    if(p_shenwang < 10)
              user_horse = new("/sgdomain/obj/dawanhorse");
	    else if(p_shenwang < 100)
	      user_horse = new("/sgdomain/obj/horse/aijiaohorse");
	    else if(p_shenwang < 1000)
              user_horse = new("/sgdomain/obj/horse/yilihorse.c");
	    else if(p_shenwang < 10000)
	      user_horse = new("/sgdomain/obj/horse/huangbiaohorse");
	    else if(p_shenwang < 80000)
	      user_horse = new("/sgdomain/obj/horse/zaohonghorse");
	    else if(p_shenwang < 200000)
	      user_horse = new("/sgdomain/obj/horse/heijunhorse");
	    else 
	      user_horse = new("/sgdomain/obj/horse/dawanhorse");
	    
	    user_horse->move(environment(this_body()));
	    user_horse->horse_master_add(p_id);
	    
	    return;
	  }
      default:
	this_object()->targetted_action("$N�ܱ�Ǹ�ض�$T"+
	"˵�������͹ٵ����⣬$sʵ����һ�㶼��֪������\n", 
					who);
	return;
      }
}

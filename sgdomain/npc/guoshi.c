#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"

inherit MONSTER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
    
void setup() 
{
  object jia,ji;
  
  set_name("guoshi", "����");
  set_proper_name("����");
  set_gender(1);
  set_age(38);
  set_in_room_desc("[�������󽫾�]����(guoshi)");
  set_cur_hp(200);
  set_cur_max_hp(200);
  set_sg_max_hp(200);
  set_sg_rongmao(23);
  init_sg_gifts(25,17,18);

  jia = new("/sgdomain/obj/cloth/armors/yinjia.c");
  jia->move(this_object());
  jia->do_wear();

  ji = new("/sgdomain/obj/weapon/ji/changji.c");
  ji->move(this_object());
  this_object()->do_wield(ji);

  add_question("����","����");
}
void special_answer(object who,string matt)
{
  int p_shenwang;
  object ob;
  object door_key;
  int changan_xi = 0;
  string changan_xi_str;
  changan_xi_str = "�˼�����(ljty)";
  p_shenwang = who->query_shengwang_int();
  switch(matt)
    {
    case "����":
      if(changan_xi)
	{
        this_object()->targetted_action(
"$N��$t˵����Կ���Ѿ��������ˣ�������Ҫ�ɡ�\n",who);
      return;
	}
      else
	{
	  if(p_shenwang < 1000) 
	    {
	      this_object()->targetted_action(
"�����$t˵�����ְλ̫���ˣ���ô��Ҫ�Ĳ��²��ܽ����㡣˵����Ҳ����$t\n",who);
	    return;
	    }
	  else
	    {
	      this_object()->targetted_action(
"���ῴ�˿�$t˵���ðɣ��ҾͰ�����½����㣬��һ��Ҫϸ�ı��ܡ�˵���ó�һ��Կ�׽�����$t\n",who);
	    
              changan_xi_str = who->query_name();
	      ob = new("/wiz/ljty/obj/door/key.c");
	      ob->move(this_object());
	      return;
	    }
	}
    default:
      this_object()->targetted_action("$N�ܱ�Ǹ�ض�$T"+
      "˵�������͹ٵ����⣬$sʵ����һ�㶼��֪������\n", 
					who);
      return;
    }
}

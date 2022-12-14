#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"

inherit MONSTER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
    
void setup() 
{
  object jia,ji;
  
  set_name("guoshi", "郭汜");
  set_proper_name("郭汜");
  set_gender(1);
  set_age(38);
  set_in_room_desc("[汉王朝大将军]郭汜(guoshi)");
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

  add_question("西门","西门");
}
void special_answer(object who,string matt)
{
  int p_shenwang;
  object ob;
  object door_key;
  int changan_xi = 0;
  string changan_xi_str;
  changan_xi_str = "浪迹天涯(ljty)";
  p_shenwang = who->query_shengwang_int();
  switch(matt)
    {
    case "西门":
      if(changan_xi)
	{
        this_object()->targetted_action(
"$N对$t说到：钥匙已经被拿走了，你向他要吧。\n",who);
      return;
	}
      else
	{
	  if(p_shenwang < 1000) 
	    {
	      this_object()->targetted_action(
"郭汜对$t说：你的职位太低了，这么重要的差事不能交给你。说完理也不理$t\n",who);
	    return;
	    }
	  else
	    {
	      this_object()->targetted_action(
"郭汜看了看$t说：好吧，我就把这差事交给你，你一定要细心保管。说完拿出一把钥匙交给了$t\n",who);
	    
              changan_xi_str = who->query_name();
	      ob = new("/wiz/ljty/obj/door/key.c");
	      ob->move(this_object());
	      return;
	    }
	}
    default:
      this_object()->targetted_action("$N很抱歉地对$T"+
      "说道：“客官的问题，$s实在是一点都不知道。”\n", 
					who);
      return;
    }
}

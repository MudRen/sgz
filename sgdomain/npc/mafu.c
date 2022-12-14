#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
    
private *name_list_take_horse =({ });
void setup() 
{
  object jia;
  
  set_name("mafu", "马夫");
  set_proper_name("马夫");
  set_gender(1);
  set_age(38);
  set_in_room_desc("马夫(mafu)");
  set_long("这是位老实巴交的马夫，满头大汗，脸上身上沾满了草料屑。\n");

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
"$N对$t说到：“你已经要过一匹了，怎么还要，形势吃紧，不能多给。”\n",who);
	    return;
	  }
	else
	  {
	    this_object()->targetted_action(
 "$N对$t说到：“请您稍等，小的这就给你牵马来。”\n过了一会，$N牵了一匹马，把\
缰绳放在$t的手上，对$t说：“这就是您的马了。”\n",who);
	    
	    name_list_take_horse += ({ p_id });
	    p_shenwang = who->query_shengwang_int();
	    if(p_shenwang < 10)
	      user_horse = new("/sgdomain/obj/horse/xiaohonghorse");
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
	this_object()->targetted_action("$N很抱歉地对$T"+
	"说道：“客官的问题，$s实在是一点都不知道。”\n", 
					who);
	return;
      }
}

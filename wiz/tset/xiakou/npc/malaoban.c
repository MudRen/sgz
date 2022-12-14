//  malaoban.c
//  马老板
//  created by tset 1/17/98
//  last updated by tset 2/2/98  
  
#include <mudlib.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
    
private *name_list=({ });
void receive_outside_msg(string str){
    receive_outside_msga(str);
}
string *query_channel_list() {
    return ({ "plyr_gossip" });
}  

void guess_age(string p, string g)
{  
  int age;
  int true_age = this_object()->query_age();

  if(sscanf(g, "%d", age) != 1) { 
//        write("你在瞎猜些啥呀？\n");
        return;
  }
  if(age == true_age) {
        printf("%s大吃一惊，对你说道：“客官真是神仙！\n",
                                this_object()->short());
        printf("%s神秘地告诉你：“小人听说管辂神卜，且有延年益寿之术，",
                                this_object()->short());
        printf("客官何不访求此人？”\n");
        age = random(10) + 40;
        this_object()->set_age(age);
  }
  else  {
    printf("%s对你摇了摇头：“客官且再猜猜看。”\n",this_object()->short());
  }
}
  
void setup() {
        int age = random(10) + 40;
        object jia;

        set_name("ma laoban", "马老板");
        add_id("ma", "laoban", "boss");
        set_gender(1);
        set_proper_name("马老板");
        set_in_room_desc("马老板(ma laoban)");
        set_age(age);
        set_long("一个四十开外的精瘦汉子。\n");

        jia = new("/sgdomain/obj/cloth/torso/buyi.c");
        jia->move(this_object());
        jia->move(this_object());
        jia->do_wear();

        add_question("rumors","rumors");
        add_question("age", "age"); 
        add_question("xiakou", "xiakou");
   
        add_pattern("%s走了过来。", "say 客官累了吧，快请进休息。\n");
        add_pattern("%s说道：guess %s", (: guess_age($1, $2) :) );
}
        
void special_answer(object who, string matter)
{
        switch(matter)
        {
            case "rumors":
                    this_object()->targetted_action("$N正色道："+
                    "“这世道，客官还是少管闲事为妙。”\n", who);
                    return;
            case "age":
                    this_object()->targetted_action("$N对$T呵呵的笑了几声。"+
                    "“客官何不猜上一猜？(say guess <num>)”\n", who);
                   return;
            default:
                    this_object()->targetted_action("$N很抱歉地对$T"+
                    "说道：“客官的问题，$s实在是一点都不知道。”\n", who);
                    return;
        }
}

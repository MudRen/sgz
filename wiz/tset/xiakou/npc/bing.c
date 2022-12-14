//  bing.c              
//  士兵
//  created by tset 1/16/98
//  last updated by tset 2/2/98
 
#include <mudlib.h>
 
inherit LIVING;
inherit M_ACTIONS;

inherit M_WANDER;
                        
private *name_list=({ });
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
                        
void setup()
{
        int age = random(30); 
        object jia;
                        
        if(age < 16) { age += 15; }

        set_id("shi bing", "士兵", "shibing", "bing", "soldier");
        set_gender(1);
        set_proper_name("士兵");
        set_in_room_desc("士兵(shi bing)");
        set_age(age);
        set_long("一个巡逻的士兵，正警觉地察看着四方。\n");
                        
        jia = clone_object("/sgdomain/obj/cloth/torso/buyi.c");
        jia->move(this_object());
        jia->do_wear();

        add_question("here","here" );
        add_question("name","name");
        add_question("rumors","rumors");
}

void special_answer(object who, string matter)
{
        switch(matter)
        {
                case "name":
                        this_object()->targetted_action("$N瞪了$T"+
                        "一眼，“没见我这儿正忙着呢。闪开！”\n", who);
                        return;
                case "here":  
                        this_object()->targetted_action("$N仔细地打量了$T"+
                        "一番：“连这儿是什么地方都不知道？我告诉你："+
                        "这里是"+environment(this_body())->get_brief()+
                        "。”\n", who);
                        return;
                case "rumors":
                        this_object()->targetted_action("$N不耐烦地说："+
                        "“$T没事干光打听这些闲事？一边去！”\n", who);
                        return;
        }
}


//by ljty.
 
#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"
 
inherit MONSTER;
inherit M_ACTIONS;

inherit M_WANDER;
                        
private *name_list=({ });
                        
void setup()
{
        int age = random(20);
        int rongmao = random(17);
        int p_tmp = random(5); 
        object p_armor,p_weapon;
                        
        age += 18;
        rongmao += 12;
        set_id("xunluobing","巡逻士兵");
        add_id("bing", "soldier");
        set_gender(1);
        set_proper_name("巡逻士兵");
        set_in_room_desc("巡逻士兵(xunluobing)");
        set_age(age);
        set_cur_hp(200);
        set_cur_max_hp(200);
        set_sg_max_hp(200);
        init_sg_gifts(rongmao,p_tmp+15,45-rongmao-p_tmp);
        set_sg_rongmao(rongmao);
        set_long("一个巡逻的士兵，正警觉地察看着四方。\n");
        set_movement_time(15);
        set_wander_area("ca_area");
                       
        p_armor = new("/sgdomain/obj/cloth/armors/tiejia.c");
        p_armor->move(this_object());
        p_armor->do_wear();

           if (p_tmp == 1) p_weapon =
              new("/sgdomain/obj/weapon/sword/gangjian.c");
           else if (p_tmp == 2) p_weapon =
              new("/sgdomain/obj/weapon/ji/changji.c");
           else if (p_tmp == 3) p_weapon =
              new("/sgdomain/obj/weapon/blade/dakandao.c");
           else if (p_tmp == 4) p_weapon =
              new("/sgdomain/obj/weapon/hammer/tiechui.c");
           else p_weapon =
              new("/sgdomain/obj/weapon/blade/gangdao.c");
        p_weapon->move(this_object());
       this_object()->do_wield(p_weapon);
        
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
                        this_object()->targetted_action("$N仔细地打量了$T"
+
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

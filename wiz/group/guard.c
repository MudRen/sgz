// guard.c"卫士"
#include <mudlib.h>
#include <ansi.h>
inherit MONSTER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void setup() 
{
  object jia;
  object jia1;
    set_name("wei shi","卫士");
    add_id("wei shi","guard","shi","卫士");
    set_gender(1);
    set_proper_name("卫士");
    set_in_room_desc("都亭府  卫士(wei shi)");
    set_wander_area("nono_home"); 
set_long("一位锦衣卫士，身着锦衣，手握长枪，双目精光炯炯，警惕地巡视着四周的情形。\n");
    jia=new("/wiz/nono/obj/jinyi.c");
    jia->move(this_object());
    jia->do_wear();
    jia1=new("/wiz/nono/obj/changqiang.c");
    jia1->move(this_object());
    this_object()->do_wield(jia1);
     set_sg_rongmao(25);
add_question("houfu","houfu");
}
void special_answer(object who, string matt)
{
        switch(matt)
        {
                case "houfu" :
                        this_object()->simple_action("卫士说道：“这里就是都亭侯侯府。”\n");
                        return;
        }
}

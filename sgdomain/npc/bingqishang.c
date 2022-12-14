//by ljty. 兵器商.
#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;

void setup() {
        object jia;

        set_name("bingqishang", "兵器商");
        add_id("bingqi", "shang", "boss");
        set_gender(1);
        set_proper_name("兵器商");
        set_in_room_desc("兵器商(bingqishang)");
        set_age(45);
        set_long("一个四十出头的兵器商人\n");

        jia = new("/sgdomain/obj/cloth/torso/buyi.c");
        jia->move(this_object());
        jia->move(this_object());
        jia->do_wear();

        add_question("rumors","rumors");
        add_question("buy","buy");
}
void special_answer(object who, string matter)
{
        switch(matter)
        {
            case "rumors":
                    this_object()->targetted_action("$N赶快凑过来说："+
                    "“如今兵荒马乱的，快买几件称手的兵刃吧。”\n", who);
                    return;
            case "buy":
                    this_object()->targetted_action("$N立刻叫起来："+
                    "“好啊，你可以先看看货，ｌｉｓｔ就行了。”\n",
                    who);
                    return;
            default:
                    this_object()->targetted_action("$N很抱歉地对$T"+
                    "说道：“客官的问题，$s实在是一点都不知道。”\n",
                    who);

                    return;
        }
}

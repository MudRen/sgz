// guard.c"卫士"
#include <mudlib.h>
#include <ansi.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void setup() 
{
  object jia;
    set_name("jia ding","家丁");
    add_id("jia ding","ding","家丁");
    set_gender(1);
    set_proper_name("家丁");
    set_in_room_desc("都亭府  家丁(jia ding)");
    set_wander_area("nono_home"); 
set_long("一个家丁，身着长袍。正在忙碌打扫周围。\n");
    jia=new("/wiz/nono/obj/changpao.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("阿洛走了过来。",function(string left, string right){ 
                this_object()->simple_action("家丁一躬身道：老爷，您回来啦。");
});

}

// guard.c"卫士"
#include <mudlib.h>
#include <ansi.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void receive_outside_msg(string str){
    receive_outside_msga(str);
}
void receive_private_msg(string str) {
    receive_outside_msga(str);
}
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
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
 add_pattern("农农走了%s",function(string left, string right){
		 
                respond("say 小人给夫人请安。");
});

}

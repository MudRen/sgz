// marry_yahuan.c "丫环"
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
object jia;
void setup() 
{
    add_id("ya huan","丫环","huan");
    set_gender(2);
    set_proper_name("丫环");
    set_in_room_desc("良缘堂 丫环(ya huan)");
    set_long("一个丫环，正忙着清理大堂。\n");
    jia=new("/sgdomain/obj/cloth/torso/skirt.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("%s走了%s",function(string left, string right){
                 
                respond("wanfu");
});

}


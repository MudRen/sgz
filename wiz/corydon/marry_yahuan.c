// marry_yahuan.c "Ѿ��"
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
    add_id("ya huan","Ѿ��","huan");
    set_gender(2);
    set_proper_name("Ѿ��");
    set_in_room_desc("��ͯ�ҵ� Ѿ��(ya huan)");
    set_long("һ��Ѿ������æ��������á�\n");
    jia=new("/sgdomain/obj/cloth/torso/skirt.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("%s����%s",function(string left, string right){
                 
                respond("wanfu");
});

}


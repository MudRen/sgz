// marry_servant.c "ϲ��"
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
    add_id("xi pu","ϲ��","pu");
    set_gender(1);
    set_proper_name("ϲ��");
    set_in_room_desc("��Ե��  ϲ��(xi pu)");
    set_long("һ��ϲ��������������ϲ�͡�\n");
    jia=new("/sgdomain/obj/cloth/torso/changpao.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("%s����%s",function(string left, string right){
                 
                respond("say ��ϲ����ϲ��");
});

}


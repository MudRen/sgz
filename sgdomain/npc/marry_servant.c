// marry_servant.c "Ï²ÆÍ"
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
    add_id("xi pu","Ï²ÆÍ","pu");
    set_gender(1);
    set_proper_name("Ï²ÆÍ");
    set_in_room_desc("Á¼ÔµÌÃ  Ï²ÆÍ(xi pu)");
    set_long("Ò»¸öÏ²ÆøÑóÑó£¬ÂúÁ³ºì¹âµÄÏ²ÆÍ¡£\n");
    jia=new("/sgdomain/obj/cloth/torso/changpao.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("%s×ßÁË%s",function(string left, string right){
                 
                respond("say ¹§Ï²£¬¹§Ï²£¡");
});

}


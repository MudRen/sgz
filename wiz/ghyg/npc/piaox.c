#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
#include <localtime.h>
inherit LIVING;
inherit M_WANDER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
inherit M_GREETER;
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
    set_name("piao xue", ""+HIY+"Ʈѩ"+NOR+"");
    set_gender(2);
    set_proper_name("Ʈѩ");
    set_in_room_desc(""+RED+"����"+NOR+"��"+HIR+"Ů����---"+HIY+"Ʈѩ"+NOR+"(piao xue)");
    set_long(HIY"\n������䷿���Ů���ˣ�Ҳ�������������������,\n"+
                "Ҳ�����������Ҳ����ѩ�·绨���������Ѿ����ˣ�\n"+
                "Ҳ�������ڽ����������ˣ����������Լ�����������\n"+
                "�޳�����������������һЩ����Ų��£�������ԶҲ��\n"+
                "�����ˣ������۽������ܿ������µĲ�ɣ����������Ρ�\n"+HIR
                "������������Ϣ�����������������ú�˯һ��ɡ�\n"NOR);
    set_age(18);
    set_sg_rongmao(30);
    jia=new("/sgdomain/obj/cloth/torso/longpao.c");
    jia->move(this_object());
    jia->do_wear();

      jia=new("/wiz/ghyg/obj/jinkui.c");
    jia->move(this_object());
    jia->do_wear();

    jia=new("/sgdomain/obj/weapon/sword/yitian.c");
    jia->move(this_object());
    jia->do_wield();
    init_greet();     
}
void greet(object o)
{
if (o->query_primary_id()=="ghyg" || o->query_primary_id()=="firecrow")
write(HIY"\n�װ������������Ҫ��Ҫ�Ҹ�������Եģ�Ҫ����������㣿"+
         "\nƮѩ���˵������㻳�\n"+NOR);
else 
    write(HIY"\nƮѩЦ��ӯӯ�߹������Ͱ���˵������ӭ���ιۣ�\n"+
          "����������˼����Ҫ��Ϣ�ˣ�����ҵ������ڵ�ʱ�������ɡ�\n"+HIR
          "���߰ɣ�Ҫ�������Ҫ�����ˡ�\n"+NOR+"");   
}
void do_greet(object o) 
{
call_out("greet",1,o);
}

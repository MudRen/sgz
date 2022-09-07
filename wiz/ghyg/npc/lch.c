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
    set_name("lch", ""+HIY+"�ֳ�"+NOR+"");
    set_gender(1);
    set_proper_name("�ֳ�");
    set_in_room_desc(""+RED+"����"+NOR+"��"+HIR+"������---"+HIY+"�ֳ�"+NOR+"(lch)");
 
set_long(HIY"\n��������䷿��������ˣ������������еķ绨ѩ���Ѿ�Զȥ��\n"+
         "��ʮ���ȥ��,����������������������ĽŲ����Զ�����ۡ�\n"+
         "δ�������˶��Ѿ����ڴ����ˡ����ǣ����񽭺��ϻ���������\n"+
         "�˳����ԡ���ʤǧ�̸Ц������Ĺ���¼������Ѿ�������\n"+
         "���е�һ�����Ƶ��񻰣�����Զ�����ź���������־ʿ��ǰ��\n"+                  
         "����Զ�ߣ�������������������Ĵ���������ټ�ǿ����\n"+
         "Ҳ�Ļ����䣬������ѡ������ȥ������������˵�Ѿ��ɹ������̣�\n"+
         "���Ѿ������������һ�У�ֻϣ�������������Ʈѩ,��Զ��Զ.....\n"NOR);
    set_age(22);
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

write(HIY+"\n�ֳ屧���ᱧ��������˵�������װ��ģ�������������˰ɣ��ú���Ϣһ�ᡣ\n"+NOR
);
else 
    if (o->query_primary_id()=="corydon" || o->query_primary_id()=="yesh")
      {write(HIR+"\n��ӭ��С���ѣ�����׼������ˣ�������Ҫ�Ҷ�ѽ������\n"NOR);}
     else
    {write(HIY"\n�ֳ�Ц��ӯӯ�߹������Ͱ���˵������ӭ���ιۣ�\n"+HIR+
     "����������˼���ҷ���Ҫ��Ϣ�ˡ�\n"+"���߰ɣ������������������ɡ�\n"+NOR+"");
     o->move("/a/huayin/vhall.c");
     o->start_busy(60,HIY"�ֳ�����㣺����Ƿ�������˵ļң����ԣ�����վ��һ���ӡ���"NOR);}
}
void do_greet(object o) 
{
call_out("greet",1,o);
}

//  malaoban.c
//  ���ϰ�
//  created by tset 1/17/98
//  last updated by tset 2/2/98  
  
#include <mudlib.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
    
private *name_list=({ });
void receive_outside_msg(string str){
    receive_outside_msga(str);
}
string *query_channel_list() {
    return ({ "plyr_gossip" });
}  

void guess_age(string p, string g)
{  
  int age;
  int true_age = this_object()->query_age();

  if(sscanf(g, "%d", age) != 1) { 
//        write("����Ϲ��Щɶѽ��\n");
        return;
  }
  if(age == true_age) {
        printf("%s���һ��������˵�������͹��������ɣ�\n",
                                this_object()->short());
        printf("%s���صظ����㣺��С����˵�����񲷣�������������֮����",
                                this_object()->short());
        printf("�͹ٺβ�������ˣ���\n");
        age = random(10) + 40;
        this_object()->set_age(age);
  }
  else  {
    printf("%s����ҡ��ҡͷ�����͹����ٲ²¿�����\n",this_object()->short());
  }
}
  
void setup() {
        int age = random(10) + 40;
        object jia;

        set_name("ma laoban", "���ϰ�");
        add_id("ma", "laoban", "boss");
        set_gender(1);
        set_proper_name("���ϰ�");
        set_in_room_desc("���ϰ�(ma laoban)");
        set_age(age);
        set_long("һ����ʮ����ľ��ݺ��ӡ�\n");

        jia = new("/sgdomain/obj/cloth/torso/buyi.c");
        jia->move(this_object());
        jia->move(this_object());
        jia->do_wear();

        add_question("rumors","rumors");
        add_question("age", "age"); 
        add_question("xiakou", "xiakou");
   
        add_pattern("%s���˹�����", "say �͹����˰ɣ��������Ϣ��\n");
        add_pattern("%s˵����guess %s", (: guess_age($1, $2) :) );
}
        
void special_answer(object who, string matter)
{
        switch(matter)
        {
            case "rumors":
                    this_object()->targetted_action("$N��ɫ����"+
                    "�����������͹ٻ����ٹ�����Ϊ���\n", who);
                    return;
            case "age":
                    this_object()->targetted_action("$N��$T�Ǻǵ�Ц�˼�����"+
                    "���͹ٺβ�����һ�£�(say guess <num>)��\n", who);
                   return;
            default:
                    this_object()->targetted_action("$N�ܱ�Ǹ�ض�$T"+
                    "˵�������͹ٵ����⣬$sʵ����һ�㶼��֪������\n", who);
                    return;
        }
}

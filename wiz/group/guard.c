// guard.c"��ʿ"
#include <mudlib.h>
#include <ansi.h>
inherit MONSTER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void setup() 
{
  object jia;
  object jia1;
    set_name("wei shi","��ʿ");
    add_id("wei shi","guard","shi","��ʿ");
    set_gender(1);
    set_proper_name("��ʿ");
    set_in_room_desc("��ͤ��  ��ʿ(wei shi)");
    set_wander_area("nono_home"); 
set_long("һλ������ʿ�����Ž��£����ճ�ǹ��˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
    jia=new("/wiz/nono/obj/jinyi.c");
    jia->move(this_object());
    jia->do_wear();
    jia1=new("/wiz/nono/obj/changqiang.c");
    jia1->move(this_object());
    this_object()->do_wield(jia1);
     set_sg_rongmao(25);
add_question("houfu","houfu");
}
void special_answer(object who, string matt)
{
        switch(matt)
        {
                case "houfu" :
                        this_object()->simple_action("��ʿ˵������������Ƕ�ͤ������\n");
                        return;
        }
}

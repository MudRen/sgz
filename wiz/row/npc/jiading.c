// guard.c"��ʿ"
#include <mudlib.h>
#include <ansi.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void setup() 
{
  object jia;
    set_name("jia ding","�Ҷ�");
    add_id("jia ding","ding","�Ҷ�");
    set_gender(1);
    set_proper_name("�Ҷ�");
    set_in_room_desc("��ͤ��  �Ҷ�(jia ding)");
    set_wander_area("nono_home"); 
set_long("һ���Ҷ������ų��ۡ�����æµ��ɨ��Χ��\n");
    jia=new("/wiz/nono/obj/changpao.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("�������˹�����",function(string left, string right){ 
                this_object()->simple_action("�Ҷ�һ���������ү������������");
});

}

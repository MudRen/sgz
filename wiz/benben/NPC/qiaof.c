// �Է� write by benben 
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void setup() 
{
    set_name("Qiao Fu", "�Է�");
    add_id("qiaofu","Qiao","fu","qiao fu","�Է�");
    set_gender(1);
    set_proper_name("�Է�");
    set_in_room_desc("�Է�(Qiao Fu)");
    set_wander_area("caolu_area"); 
    set_long("һ���Է�ͷ�ϴ����ң����ϴ����£�����ϵ�Ż��У�����̤�Ų��ģ�
��ִһ���ָ������ڿ�����\n\n");
        add_question("wolonggang","wolonggang");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "wolonggang" :
			this_object()->simple_action("�Է�˵��������Զ����Զ���������Ӿ��ǡ���\n");
			return;
	}
}

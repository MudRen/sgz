//**********************************************
// write by benben 29/12/97 benben.c С����
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
void setup() 
{
    set_name("farmer", "ũ��");
    add_id("farmer","ũ��");
    set_gender(1);
    set_proper_name("ũ��");
    set_in_room_desc("ũ��(farmer)");
    set_wander_area("caolu_area"); 
    set_long("һ��ũ�򣬺ɳ���������䡣\n\n");
	add_question("zhuge","kongming","�����","����");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "zhuge" :
			this_object()->simple_action("ũ��˵�������Դ�ɽ֮�ϣ�һ���߸ԣ���������Ҳ����ǰ������é®
�У��������������֮�ء���\n");
			return;
	}
}
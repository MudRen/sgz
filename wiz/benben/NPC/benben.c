//**********************************************
// write by benben 29/12/97 benben.c С����
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
void setup() 
{
    set_name("ben ben", "С����");
    add_id("ben ben","ben","С����");
    set_gender(2);
    set_proper_name("С����");
    set_in_room_desc("�������С����(Ben ben)");
    set_long("С������æ����ͷ�󺹣���������ء�һ̧ͷ�����㣺\n"+"�������Ÿ���������æ������Щ�ó������üһ��\n\n");
	add_question("food","food");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "food" :
			this_object()->simple_action("С�����˸߲��ҵ�˵���������������͡�����ȫϯ�����������ǳ�����OKȥ����\n");
			return;
	}
}

//**********************************************
// write by fire 10/12/97 xiaoer.c ��С��
#include <mudlib.h>
inherit LIVING;
void setup() 
{
    set_name("xiaoer", "���������");
    add_id("xiao","er");
    set_gender(1);
    set_proper_name("����Źֵİ��������");
    set_in_room_desc("���������İ��������");
    set_long("���������̧ͷ������һ�ۣ�\n"+"���Ҵ�Ŷ��\n\n");
    set_sg_zi("С��");
	add_question("rumors","rumors" );
	add_question("food","food");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "rumors" :
			this_object()->targetted_action("$N��$T����˵����������˵����������Ҫ�Ǽ�ѽ����\n",who);
			return;
		case "food" :
			this_object()->simple_action("С������һ�ۣ���Ҫ�ҳԵģ���Ǯ��ѽ����\n");
			return;
	}
}

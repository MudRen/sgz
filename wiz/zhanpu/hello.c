//**********************************************
// write by fire 10/12/97 xiaoer.c ��С��
#include <mudlib.h>
inherit LIVING;
void setup() 
{
    add_id("xiao","er")
    set_name("xiaoer", "���������")
    set_gender(1)
    set_proper_name("����Źֵİ��������")
    set_in_room_desc("���������İ��������")
    set_long("���������ճյ������㣬\n"+"��ɱ��Ҵ�Ŷ��\n\n")
    set_sg_zi("����")
        add_question("zhanpu","zhanpu" )
        add_question("money","money")
}
void special_answer(object who, string matt)
{
        switch(matt)
        {
                case "zhanpu" :
                        this_object()->targetted_action("$N��$T������˵�������ɶ��ҵ����˲�������Ȼ�������㣡��\n",who)
                        return
                case "money" :
                        this_object()->simple_action("�����������ӵؿ����㣺����û��û�Ű���Ҫ���л��ӣ���\n")
 return
        }
}

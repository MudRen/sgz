#include <mudlib.h>
inherit LIVING;
inherit M_CHAR;
void receive_outside_msg(string msg, object array exclude, int message_type,
                         mixed other)
{
    responda("say "+msg);
    receive(msg);
}
void ppp(object me,object who,string item)
{
        me->targetted_action("$N����$T������Ц",who);
}
void setup()
{
    set_name("farmer", "ũ��");
    set_gender(1);
    set_proper_name("���۵�ũ��");
    set_in_room_desc("һ���۵ð�����ũ��(farmer)");
    set_long("ũ�������һ�ۣ������ݶ��͵ļһ����������æ�����ء���");
    set_answer("net", (: ppp :)) ;
}
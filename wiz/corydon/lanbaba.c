#include <mudlib.h>
inherit LIVING;
void ppp(object me,object who,string item)
{
        me->targetted_action("$N����$T������Ц",who);
}
void setup()
{
    set_name("papasmurf", "���ְ�");
    set_gender(1);
    set_proper_name("ѩ�׺�������ְ�");
    set_in_room_desc("%^H_BLUE%^���ְ�%^RESET%^(papasmurf)���ڵ���ҩ... fear");
    set_long("���ְֵ�����һ�ۣ������ң�æ����!��");
    set_answer("net", (: ppp :)) ;
}

#include <mudlib.h>
inherit LIVING;
void ppp(object me,object who,string item)
{
        me->targetted_action("$N����$T������Ц",who);
}
void setup()
{
    set_name("smuffette", "������");
    set_gender(2);
    set_proper_name("���ε�������");
    set_in_room_desc("%^H_BLUE%^������%^RESET%^(smuffette)����������С����첻˵�� :%^RED%^0%^RESET%^");
    set_long("%^H_BLUE%^������%^RESET%^������§����Ĳ���˵���װ���İ���ˣ�����ȥ����ɡ�����");
    set_answer("net", (: ppp :)) ;
}

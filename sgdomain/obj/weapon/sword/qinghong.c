#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", HIG+"��罣"+NOR);
add_id("qing");
add_id("hong");
add_id("qinghong");
set_in_room_desc(HIG+"��罣"+NOR+"(qing hong)");
set_long("��������ı�����ԭΪ�ĺ�����壬��Ϊ���廢����֮һ���������ã� ����۳ҽ�����ն�����������\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(200);
set_attack_power(140);
set_defence_ability(200);
   set_combat_messages("combat-sword");
set_wield_message("$Nһ�����ʣ�ֻ���á��ס���һ����$oԽ�ʶ����� ������磬����Ŀѣ��\n");
set_unwield_message("$N����������������ʣ�����һ�������է�ա�\n");
}

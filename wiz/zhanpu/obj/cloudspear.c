#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("cloudspear", HIG+"��������ǹ"+NOR);
add_id("cloud");
add_id("spear");
add_id("cloud");
set_in_room_desc(HIG+"��������ǹ"+NOR+"(fangtianhua ji)");
set_long("������������������������������������ǹ�������
���˰���ϧ�֡�\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(180);
set_attack_power(140);
set_defence_ability(180);
set_combat_messages("combat-spear");
set_wield_message("$N����һ��ǹ�����ѽ�$o������������������𣬺�һ���𼦶�����ɲʱ�Ե�������Ů��\n");
set_unwield_message("$N�������Σ�����һ��ѽ�$o�����ͷ��\n");
}

#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("blade", "����");
add_id("dao");
add_id("dan dao");
set_in_room_desc("����(dan dao)");
set_long("����һ����ͨ�ĵ�����������̶��г��ۣ�����
�󻹴���һ�κ��\n");
set_size(MEDIUM);
set_value(10);
set_currency_type("silver");
set_attack_ablity(50);
set_attack_power(20);
set_defence_ablity(50);
set_combat_messages("combat-blade");
set_wield_message("$N��Ǻॡ�һ�����һ��$o���������С�\n");
set_unwield_message("$N����һ����������$o������С�\n");
}
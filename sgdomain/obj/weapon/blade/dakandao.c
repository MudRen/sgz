#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("dakan dao", "�󿳵�");
add_id("dakan dao");
add_id("dao");
add_id("blade");
set_in_room_desc("�󿳵�(dakan dao)");
set_long("��ͨ�ĳ�������ȫ��һ�����ߣ���ͷ����������
���У�Ϊ����佫��սʱ���ֵı��С�\n");
set_size(MEDIUM);
set_value(2);
set_currency_type("silver");
set_attack_ability(100);
set_attack_power(80);
set_defence_ability(100);
set_combat_messages("combat-blade");
set_wield_message("$N����һ�ӣ���$o������ǰ��\n");
set_unwield_message("$N����һ����������$o�����ͷ��\n");
}

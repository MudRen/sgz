#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("chang qiang", "��ǹ");
add_id("chang qiang","qiang");
set_in_room_desc("��ǹ(chang qiang)");
set_long("һ����ǹ��ǹͷ����һ����ӧ����ͨ��ʿ�ĳ���������\n");
set_size(MEDIUM);
set_value(30);
set_currency_type("silver");
set_attack_ability(30); 
set_attack_power(50);
set_defence_ability(80); 
set_combat_messages("combat-ji");
set_wield_message("$N��סһ����ǹ�����˸�ǹ������ӧ������\n");
set_unwield_message("$N�������еĳ�ǹ��\n");
}

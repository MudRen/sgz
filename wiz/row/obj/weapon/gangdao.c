#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("gang dao","�ֵ�");
add_id("dao");
add_id("blade");
set_in_room_desc("�ֵ�(gang dao)");
set_long("��������ִ��ƶ��ɵĵ������ʵؽ���ͨ������
Ϊ���ͣ��Ǿ�����������䱸��\n");
set_size(MEDIUM);
set_value(30);
set_currency_type("silver");
set_attack_ablity(80);
set_attack_power(40);
set_defence_ablity(80);
set_combat_messages("combat-blade");
set_wield_message("$N��Ǻॡ�һ�����һ��$o���������С�\n");
set_unwield_message("$N����һ����������$o������С�\n");
}
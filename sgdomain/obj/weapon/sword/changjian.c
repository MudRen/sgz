#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", "����");
add_id("changjian");
set_in_room_desc("����(changjian)");
set_long("����һ����ͨ�ĳ�����������̶��г��ۣ�ľ�ƵĽ��������� ���ƽ�ƵĽ��롣\n");
set_size(MEDIUM);
set_value(10);
set_currency_type("silver");
set_attack_ability(50);
set_attack_power(20);
set_defence_ability(50);
   set_combat_messages("combat-sword");
set_wield_message("$N��ৡ���һ�����һ��$o���������С�\n");
set_unwield_message("$N�������������������ػ������ʡ�\n");
}

#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", "�ֽ�");
add_id("gangjian");
set_in_room_desc("�ֽ�(gangjian)");
set_long("��������ִ�����ɵĳ������ʵؼ��ͣ������۶ϣ�Ϊ������ٱ���ϲ�� �Ķ̱�����\n");
set_size(MEDIUM);
set_value(30);
set_currency_type("silver");
set_attack_ability(80);
set_attack_power(40);
set_defence_ability(80);
   set_combat_messages("combat-sword");
set_wield_message("$N��ৡ���һ�����һ��$o���������С�\n");
set_unwield_message("$N�������������������ػ������ʡ�\n");
}

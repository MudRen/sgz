#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", HIR+"ľ��"+NOR);
add_id("mujian");
set_in_room_desc(HIR+"ľ��"+NOR+"(mujian)");
set_long("���ľ���������ᣬ�������ŵ�һ��̴�㣬��ɫ��ζ�� ��ʵ���˰������֡�\n");
set_size(SMALL);
set_value(-1);
set_currency_type("gold");
set_attack_ability(10);
set_attack_power(5);
set_defence_ability(10);
   set_combat_messages("combat-sword");
set_wield_message("$N�����γ�һ��$o���������ء�\n");
set_unwield_message("$NС������ؽ�$o���ľ�ʡ�\n");
}

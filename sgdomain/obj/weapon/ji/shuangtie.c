#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("shuangtie ji", HIB+"˫���"+NOR);
add_id("shuangtie ji");
add_id("ji");
add_id("shuangtie");
set_in_room_desc(HIB+"˫���"+NOR+"(shuangtie ji)");
set_long("κ��������Τ�Ķ��ű�����Ϊһ���������ɵĶ�ꪣ���
���˳��࣬ʮ�����ɡ�\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(140);
set_attack_power(115);
set_defence_ability(140);
set_combat_messages("combat-ji");
set_wield_message("$N˫��һ�֣���$o��������ǰ���������ݡ�\n");
set_unwield_message("$N˫��һ�ϣ���$o������䡣\n");
}

#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("qinglongyanyue dao", HIC+"�������µ�"+NOR);
add_id("qinglong");
add_id("qinglongyanyue dao");
add_id("blade");
add_id("dao");
set_in_room_desc(HIC+"�������µ�"+NOR+"(qinglongyanyue dao)");
set_long("����ʥ������֮���ű�������Լһ���߳ߣ��ش���ʮ���
�����ϵ�������ͼ����\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(180);
set_attack_power(140);
set_defence_ability(180);
set_combat_messages("combat-blade");
set_wield_message("ֻ����һ�����𣬻�����������ؼ������������֣�
$N����˫�ۣ���$o�߸߾���\n");
set_unwield_message("$N˫������һ�ڣ���$o
�����ͷ�����һ�����������š�\n");
}

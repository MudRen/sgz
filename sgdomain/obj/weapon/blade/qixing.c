#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("qixing dao", HIC+"���ǵ�"+NOR);
add_id("qixing");
add_id("dao");
add_id("blade");
add_id("qixing dao");
set_in_room_desc(HIC+"���ǵ�"+NOR+"(qixing dao)");
set_long("��ֵ���ǵı��������䵶��������������ʯ�������������ǡ���
�˵�ԭΪ˾�������У���Ϊ�ܲ����裬���׵�֮����ɱ��׿��\n");
set_size(MEDIUM);
set_value(50000);
set_currency_type("gold");
set_attack_ability(150);
set_attack_power(100);
set_defence_ability(150);
set_combat_messages("combat-blade");
set_wield_message("ֻ��һ���߲ʻ��⣬$N�ѽ�$o�����������ǰ��\n");
set_unwield_message("$N����һ����$o�������ʣ��߲ʹ�âһ�Ӷ��š�\n");
}

#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("xuanhua fu", HIC+"������"+NOR);
add_id("xuanhua fu");
add_id("xuanhua");
add_id("fu");
add_id("axe");
set_in_room_desc(HIC+"������"+NOR+"(xuanhua fu)");
set_long("κ���������֮���ű������ش���ʮ�˽������
�����軨ͼ����\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ablity(170);
set_attack_power(130);
set_defence_ablity(170);
set_combat_messages("combat-ji");
set_wield_message("$N˫��һ���������$o��������棬������η��\n");
set_unwield_message("$N��$o����һ�ڣ����ȵؼ���\n");
}
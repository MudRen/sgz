#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", HIG+"˫�ɽ�"+NOR);
add_id("shuang");
add_id("gu");
add_id("shuang gu");
set_in_room_desc(HIG+"˫�ɽ�"+NOR+"(shuang gu)");
set_long("һ�Ծ��ִ���ı�����ԭΪ�����������������壬 ���Եü��ֹ�����\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(100);
set_attack_power(80);
set_defence_ability(100);
   set_combat_messages("combat-sword");
set_wield_message("$N�ν�������˫��һ�֣����潫$o������ǰ�� ���ƷǷ���\n");
set_unwield_message("$N˫��һ�ϣ��������ʡ�\n");
}

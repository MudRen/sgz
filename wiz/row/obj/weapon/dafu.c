#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("da fu", "��");
add_id("da fu");
add_id("fu");
add_id("axe");
set_in_room_desc("��(da fu)");
set_long("��Ϊ���ص���ս��������Ϊ����ǿ��֮�佫���ã���ͷ
�������ַ�����\n");
set_size(MEDIUM);
set_value(500);
set_currency_type("silver");
set_attack_ablity(110);
set_attack_power(95);
set_defence_ablity(110);
set_combat_messages("combat-ji");
set_wield_message("$N����˫�ۣ���$o�ٹ�ͷ����\n");
set_unwield_message("$N˫�ۻ��裬�ѽ�$o����\n");
}
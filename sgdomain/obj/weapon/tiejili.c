#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("tiejili guduo", HIW+"����޼�Ƕ�"+NOR);
add_id("tiejili guduo");
add_id("tiejili");
add_id("guduo");
set_in_room_desc(HIW+"����޼�Ƕ�"+NOR+"(tiejili guduo)");
set_long("�������õĶ��ұ�����ò����������������������
��̣�������η��\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ablity(150);
set_attack_power(115);
set_defence_ablity(150);
set_combat_messages("combat-hammer");
set_wield_message("$N˫��һ�֣���$o�������У�����ʮ�㡣\n");
set_unwield_message("$N˫��һ�ϣ��ѽ�$o����\n");
}

#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("hutougoulian qiang", HIY+"��ͷ����ǹ"+NOR);
add_id("hutougoulian qiang");
add_id("qiang");
add_id("hutougoulian");
set_in_room_desc(HIY+"��ͷ����ǹ"+NOR+"(hutougoulian qiang)");
set_long("�ϵȵ���ս�����У�ǹ���ɻ������ɣ�ǹ��һ����
�࣬β���ʻ�ͷ״�������з���������\n");
set_size(MEDIUM);
set_value(5000);
set_currency_type("gold");
set_attack_ablity(150);
set_attack_power(120);
set_defence_ablity(150);
set_combat_messages("combat-ji");
set_wield_message("$N˫��һ�ڣ���$o�������У�����ৡ�������¡�\n");
set_unwield_message("$N������$o���ԲȦ�������ͷ��\n");
}
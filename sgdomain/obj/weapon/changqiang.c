#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("chang qiang", "��ǹ");
add_id("chang qiang");
add_id("qiang");
set_in_room_desc("��ǹ(chang qiang)");
set_long("��ͨ�ĳ������������ǹͷ�󻹴���������ɫǹ�룬Ϊ
����佫���õ�������ս���С�\n");
set_size(MEDIUM);
set_value(500);
set_currency_type("silver");
set_attack_ablity(90);
set_attack_power(75);
set_defence_ablity(90);
set_combat_messages("combat-ji");
set_wield_message("$N˫��һ����������$o��������ԲȦ��\n");
set_unwield_message("$N���ֽ�$o�����ͷ��\n");
}
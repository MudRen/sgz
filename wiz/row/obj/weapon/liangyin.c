#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("liangyin qiang", HIW+"����ǹ"+NOR);
add_id("liangyin qiang");
add_id("liangyin");
add_id("qiang");
set_in_room_desc(HIW+"����ǹ"+NOR+"(liangyin qiang)");
set_long("������ͨ��ǹ��ǹ���ɾ������ɣ����ͷ�����\n");
set_size(MEDIUM);
set_value(1000);
set_currency_type("silver");
set_attack_ablity(110);
set_attack_power(90);
set_defence_ablity(110);
set_combat_messages("combat-ji");
set_wield_message("ֻ������һ����$N����˫�ֽ�$o�������С�\n");
set_unwield_message("$N������$o�������������������ͷ��\n");
}
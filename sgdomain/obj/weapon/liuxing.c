#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("liuxing chui", HIY+"�����"+NOR);
add_id("liuxing chui");
add_id("liuxing");
add_id("chui");
set_in_room_desc(HIY+"�����"+NOR+"(liuxing chui)");
set_long("������˫֮���ű�������ֻ��ϴ�С������ɾ�����
�ɵ�����˩��һ��\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ablity(130);
set_attack_power(110);
set_defence_ablity(130);
set_combat_messages("combat-hammer");
set_wield_message("$N˫��һ�֣��ͳ���������֮$o����û������硣\n");
set_unwield_message("$N˫��һ�ϣ�����$o�����ַŻػ��С�\n");
}

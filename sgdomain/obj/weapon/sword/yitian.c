#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", HIG+"���콣"+NOR);
add_id("yi");
add_id("tian");
add_id("yitian");
set_in_room_desc(HIG+"���콣"+NOR+"(yi tian)");
set_long("��������ı�����ԭ�롸��硹һ��Ϊ�ĺ�����壬 �����ĺ��Ϊ������ն���ɲܲ������\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(200);
set_attack_power(140);
set_defence_ability(200);
   set_combat_messages("combat-sword");
set_wield_message("$Nһ�����ɣ�$o���ʶ�������շ��������С����죬���� ���ˡ�\n");
set_unwield_message("$N������$o���ʣ����Ǻ��������߽���һ���������š�\n");
}

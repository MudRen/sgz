#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("zhangbashe mao", HIW+"�ɰ���ì"+NOR);
add_id("zhangbashe mao");
add_id("zhangbashe");
add_id("mao");
set_in_room_desc(HIW+"�ɰ���ì"+NOR+"(zhangbashe mao)");
set_long("���廢�Ͻ���֮һ�ŷ�֮���ű�������һ�ɰ˳���
�࣬ì���������ߣ�ͷ�����̣�������״��\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ablity(180);
set_attack_power(140);
set_defence_ablity(180);
set_combat_messages("combat-ji");
set_wield_message("$Nһ���Ϻȣ���������$o����û������磬�����쳣��\n");
set_unwield_message("$N�������������$oһ�ڣ������ͷ��\n");
}
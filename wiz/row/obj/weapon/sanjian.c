#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sanjianliangren dao", HIW+"�������е�"+NOR);
add_id("sanjianliangren dao");
add_id("dao");
add_id("sanjian");
add_id("blade");
set_in_room_desc(HIW+"�������е�"+NOR+"(sanjianliangren dao)");
set_long("��״���صĳ�������һ��������࣬�����ɻ������ɣ�
�ĳ߳�֮���ֵ�����������̣����࿪�У������ޱȡ�\n");
set_size(MEDIUM);
set_value(1000);
set_currency_type("silver");
set_attack_ablity(120);
set_attack_power(80);
set_defence_ablity(120);
set_combat_messages("combat-blade");
set_wield_message("$N���һ����˫������һ�ڣ���$o�������С�\n");
set_unwield_message("$N������Σ�����һ�ӣ����ѽ�$o�����ͷ��\n");
}
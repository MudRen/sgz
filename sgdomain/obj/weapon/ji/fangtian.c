#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("fangtianhua ji", HIG+"���컭�"+NOR);
add_id("fangtianhua ji");
add_id("ji");
add_id("fangtianhua");
set_in_room_desc(HIG+"���컭�"+NOR+"(fangtianhua ji)");
set_long("��һ��ʿ���º����֮���ű�������һ���߳ߣ�ǹͷ
�������������εĵ��档\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ability(180);
set_attack_power(140);
set_defence_ability(180);
set_combat_messages("combat-ji");
set_wield_message("$N˫��һ�ڣ��ѽ�$o�������У�������ң����˿ɵ���\n");
set_unwield_message("$N�������Σ�����һ��ѽ�$o�����ͷ��\n");
}

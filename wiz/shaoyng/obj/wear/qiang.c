#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
    set_unit("֧");
    set_id("jqiang", HIY+"�����ɽ�ǹ"+NOR);
    set_in_room_desc(HIY+"�����ɽ�ǹ"+NOR+"(ji)");
    set_size(MEDIUM);
    set_value(5000);
    set_currency_type("gold");
    set_attack_ablity(10000);
    set_attack_power(20);
    set_defence_ablity(10000);
    set_combat_messages("combat-ji");
}


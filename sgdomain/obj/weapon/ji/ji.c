#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("ji", HIG+"���컭�"+NOR);
set_in_room_desc(HIG+"���컭�"+NOR+"(ji)");
set_size(MEDIUM);
set_value(5000);
set_currency_type("gold");
set_attack_ability(100);
set_attack_power(30);
set_defence_ability(120);
   set_combat_messages("combat-ji");
}

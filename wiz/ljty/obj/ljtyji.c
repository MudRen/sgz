#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("ljtyji", HIG+"���컭�"+NOR);
set_in_room_desc(HIG+"���컭�"+NOR+"(ljtyji)");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ablity(1000);
set_attack_power(250);
set_defence_ablity(100);
   set_combat_messages("combat-ji");
}

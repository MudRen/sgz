#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("hammer", "����");
set_in_room_desc("����");
set_size(MEDIUM);
set_value(2);
set_currency_type("gold");
set_attack_ability(20);
set_attack_power(20);
set_defence_ability(10);
   set_combat_messages("combat-hammer");
}

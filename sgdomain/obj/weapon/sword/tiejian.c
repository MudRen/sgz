#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("sword", "����");
set_in_room_desc("����");
set_size(MEDIUM);
set_value(50);
set_currency_type("silver");
set_attack_ability(40);
set_attack_power(10);
set_defence_ability(20);
   set_combat_messages("combat-sword");
}

#include <mudlib.h>

inherit M_WEAPON;
inherit M_VALUE;

void setup() {
	set_id("lian dao", "����", "knife");
	set_unit("��");
	set_in_room_desc("һ�ѷ���������(lian dao)");
	set_attack_ability(20);
	set_attack_power(10);
	set_defence_ability(1);
	set_combat_messages("combat-blade");
    set_value(300);
    set_currency_type("coin");
}
int can_cut()
{
	return 1;
}

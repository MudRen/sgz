#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("chang ji", "���");
add_id("chang ji");
add_id("ji");
set_in_room_desc("���(chang ji)");
set_long("��������ս���������Ƶ�ǹͷһ�����е�����\n");
set_size(MEDIUM);
set_value(800);
set_currency_type("silver");
set_attack_ablity(100);
set_attack_power(80);
set_defence_ablity(100);
set_combat_messages("combat-ji");
set_wield_message("$N��������һ������$o�������С�\n");
set_unwield_message("$N˫��һ�ڣ���$o����\n");
}

#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
inherit M_VALUE;
void setup()
{
::mudlib_setup();
set_unit("��");
set_id("jinjia", "���");
add_id("cloth");
set_in_room_desc("���(jinjia)");
set_long("һ�����Ĵ���Ľ�ף�ֻ������ս�Ľ��������ʸ񴩡�");
set_gettable(1);
set_slot(ARMORS);
set_wearmsg("$N����һ��$o���۾������Ź⣬�����Ǳ����ã��������ݡ�\n");
set_removemsg("$N����һ��$o��\n");
set_attack_ablity(-10);                           
set_defence_power(50);
set_defence_ablity(-5);
set_rongmao(1);
set_value(1);
set_currency_type("gold");
}                                               

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
set_id("yinjia", "����");
add_id("cloth");
set_in_room_desc("����(yinjia)");
set_long("һ�����������������ס�");
set_gettable(1);
set_slot(ARMORS);
set_wearmsg("$N����һ��$o��ʮ��Ӣ�䣬�˲ų��ڡ���һ�����꽫����\n");
set_removemsg("$N����$o��\n");
set_attack_ablity(-10);                           
set_defence_power(40);
set_defence_ablity(-5);
set_rongmao(1);
set_value(1);
set_currency_type("gold");
}                                               
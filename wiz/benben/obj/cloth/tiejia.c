
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
set_id("tiejia", "����");
add_id("cloth");
set_in_room_desc("����(tiejia)");
set_long("һ�����ף���Ƭ���������죬������Щ���ء�");
set_gettable(1);
set_slot(ARMORS);
set_wearmsg("$N����һ��$o������֮��������\n");
set_removemsg("$N����$o���������ɶ��ˡ�\n");
set_attack_ablity(-10);                           
set_defence_power(30);
set_defence_ablity(-10);
set_rongmao(0);
set_value(1);
set_currency_type("silver");
}                                               
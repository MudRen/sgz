
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
set_id("choupao", "����");
add_id("cloth");
set_in_room_desc("����(choupao)");
set_long("һ�����������ĳ��ۡ�");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����һ��$o��ٲȻ������˼ң���ʱ���������\n");
set_removemsg("$N����$o������֮����ʧ���������ֻ������С�ӡ�\n");
set_attack_ablity(-1);                          
set_defence_power(1);
set_defence_ablity(-1);
set_rongmao(0);
set_value(1);
set_currency_type("silver");
}                                               
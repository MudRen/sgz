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
set_id("buyi", "����");
add_id("cloth");
set_in_room_desc("����(buyi)");
set_long("һ��ƽ���İײ��£���Ȼ�Ǵֲ����ģ���Ҳ�ʹ���");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����һ������ͨͨ��$o�� \n");
set_removemsg("$N������������һ��$o�������������ȥ���ɣ�\n");
set_attack_ablity(-1);                          
set_defence_power(1);
set_defence_ablity(-1);
set_rongmao(0);
set_value(1);
set_currency_type("coin");
}                                               
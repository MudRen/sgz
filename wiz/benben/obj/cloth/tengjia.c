
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
set_id("tengjia", "�ټ�");
add_id("cloth");
set_in_room_desc("�ټ�(tengjia)");
set_long("һ���ټף����ͷ������ݣ���ɹ�˼�ʮ����Ƴɵģ���Ӳ�ֻ�������
���롣");
set_gettable(1);
set_slot(ARMORS);
set_wearmsg("$N����һ�����ɵ��ټ�$o������ȴ�������롣\n");
set_removemsg("$N����һ��$o��\n");
set_attack_ablity(-5);                           
set_defence_power(40);
set_defence_ablity(-3);
set_rongmao(0);
set_value(1);
set_currency_type("silver");
}                                               
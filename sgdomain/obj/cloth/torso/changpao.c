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
set_id("pao","��ɫ����");
add_id("cloth","changpao");
set_in_room_desc("��ɫ����(chang pao)");
set_long("һ������ͨ�ĳ��ۡ�");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����һ����ɫ���ۡ�\n");
set_removemsg("$N����һ����ɫ���ۡ�\n");
set_attack_ability(0);                          
set_defence_power(0);
set_defence_ability(0);
set_rongmao(0);
set_value(10);
set_currency_type("silver");
}                                             
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
set_id("siyi","˿��");
add_id("cloth");
set_in_room_desc("˿��(siyi)");
set_long("��Ȼֻ��һ��˿�£�����ʹ�Ĳ���ȴ���ϵȵġ�");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����һ��˿�¡�\n");
set_removemsg("$N����һ��˿��\n");
set_attack_ability(0);   
set_defence_power(0);
set_defence_ability(0);
set_rongmao(0);
set_value(1);
set_currency_type("silver");
}                                         
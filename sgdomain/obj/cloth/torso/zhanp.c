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
    set_id("zhanpao", "ս��");
    add_id("pao");
    set_in_room_desc("ս��(zhanpao)");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N����$o��һ����װ��Ӣ��������\n");
    set_removemsg("$N����$o��\n");
    set_attack_ability(10);
    set_defence_power(10);
    set_defence_ability(-1);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver");
}

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
    set_id("tongkui", "ͭ��");
    add_id("kui");
    set_in_room_desc("ͭ��(tongkui)");
    set_long("һ����ͭ������ͷ����");
    set_gettable(1);
    set_slot(HEAD);
    set_wearmsg("$N����һ��$o��\n");
    set_removemsg("$N����һ��$o��\n");
    set_attack_ability(-2);
    set_defence_power(5);
    set_defence_ability(-2);
    set_rongmao(1);
    set_value(20);
    set_currency_type("silver");
}

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
    set_id("yinkui", "����");
    add_id("kui");
    set_in_room_desc("����(yinkui)");
    set_long("һ��������������");
    set_gettable(1);
    set_slot(HEAD);
    set_wearmsg("$N����һ��$o��\n");
    set_removemsg("$N����һ��$o��\n");
    set_attack_ability(-3);
    set_defence_power(8);
    set_defence_ability(-2);
    set_rongmao(1);
    set_value(50);
    set_currency_type("silver");
}

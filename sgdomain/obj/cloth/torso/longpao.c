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
    set_id("longpao", HIY"����"NOR);
    add_id("pao");
    set_in_room_desc(HIY"����"NOR+"(longpao)");
    set_long("һ�����ž�����������");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N����$o������������������ա�\n");
    set_removemsg("$N����$o��\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(30);
    set_value(5000);
    set_currency_type("silver");
}

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
    set_unit("˫");
    set_id("pixue", "Ƥѥ");
    add_id("shoes", "xue");
    set_in_room_desc("Ƥѥ(pixue)");
    set_long("һ˫Ƥѥ��");
    set_gettable(1);
    set_slot(FEET);
    set_wearmsg("$N����һ˫$o��\n");
    set_removemsg("$N����һ˫$o��\n");
    set_attack_ability(-1);
    set_defence_power(3);
    set_defence_ability(-1);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver"); 
}

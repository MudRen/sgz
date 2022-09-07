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
    set_unit("Ë«");
    set_id("pixue", "Æ¤Ñ¥");
    add_id("shoes", "xue");
    set_in_room_desc("Æ¤Ñ¥(pixue)");
    set_long("Ò»Ë«Æ¤Ñ¥¡£");
    set_gettable(1);
    set_slot(FEET);
    set_wearmsg("$N´©ÉÏÒ»Ë«$o¡£\n");
    set_removemsg("$NÍÑÏÂÒ»Ë«$o¡£\n");
    set_attack_ability(-1);
    set_defence_power(3);
    set_defence_ability(-1);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver"); 
}

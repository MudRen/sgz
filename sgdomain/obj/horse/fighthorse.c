// fight horse. by ljty 1998.03.28
#include <sanguo.h>
#include "/wiz/ljty/ljty.h"
inherit M_HORSE_1;
inherit M_VALUE;
void setup()
{
    set_id("fighthorse", "ս��");
    add_id("zhanhorse");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("ƥ");
    set_long("ս��");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("ս��(fighthorse)");
    set_value(200);
    set_currency_type("silver");
    set_attack_ability(100);
    set_defence_ability(100);
    set_attack_power(10);
}


/// horse1.c
#include <sanguo.h>
inherit M_HORSE;
inherit M_VALUE;
void setup()
{
    set_id("horse", "ս��");
   set_relations("on");
    set_unit("ƥ");
    set_long("һƥս��");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("һƥս��(horse)");
    set_value(2);
    set_currency_type("gold");
    set_attack_ability(100);
    set_defence_ability(100);
    set_attack_power(10);
}

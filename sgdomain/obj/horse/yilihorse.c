#include <sanguo.h>
#include "/wiz/ljty/ljty.h"
inherit M_HORSE_1;
inherit M_VALUE;
void setup()
{
    set_id("yilihorse", "������");
    add_id("yili");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("ƥ");
    set_long("����һƥ�����������������ɳ۳Ұ˰��");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("������(yilihorse)");
    set_value(175);
    set_currency_type("silver");
    set_attack_ability(80);
    set_defence_ability(80);
    set_attack_power(20);

}


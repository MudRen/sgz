#include <sanguo.h>
#include "/wiz/ljty/ljty.h"
inherit M_HORSE_1;
inherit M_VALUE;
void setup()
{
    set_id("aijiaohorse", "������");
    add_id("aijiao");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("ƥ");
    set_long("����һƥ���ְ��������ͳ�;��");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("������(aijiaohorse)");
    set_value(120);
    set_currency_type("silver");
    set_attack_ability(70);
    set_defence_ability(70);
    set_attack_power(10);
}


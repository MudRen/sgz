#include <sanguo.h>

inherit M_HORSE;
inherit M_VALUE;
void setup()
{
    set_id("xiaohonghorse", "С����");
    add_id("xiaohong");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("ƥ");
    set_long("����һƥ��ɫ��������һ��ɽ����");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("С����(xiaohonghorse)");
    set_value(80);
    set_currency_type("silver");
    set_attack_ability(60);
    set_defence_ability(60);
    set_attack_power(10);
}

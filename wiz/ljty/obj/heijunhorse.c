// fight horse. by ljty 1998.03.28
#include <sanguo.h>
inherit M_HORSE;
inherit M_VALUE;
void setup()
{
    set_id("heijunhorse", "�ڿ���");
    add_id("heijun");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("ƥ");
    set_long("����һƥ�ڿ�������ȴ����ɫ������һƥ����");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("�ڿ���(heijunhorse)");
    set_value(200);
    set_currency_type("silver");
    set_attack_ability(110);
    set_defence_ability(110);
    set_attack_power(30);
}

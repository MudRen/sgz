#include <sanguo.h>
inherit M_HORSE;
inherit M_VALUE;
void setup()
{
    set_id("huangbiaohorse", "�Ʊ���");
    add_id("huangbiao");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("ƥ");
    set_long("����һƥ��ɫ�ĸ�ͷ��������ȫ���ɫ����һ����ë��");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("�Ʊ���(huangbiaohorse)");
    set_value(120);
    set_currency_type("silver");
    set_attack_ability(90);
    set_defence_ability(90);
    set_attack_power(20);
}

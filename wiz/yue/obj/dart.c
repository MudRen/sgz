// by fire on Dec 11 1997 dart.c ذ��
#include <sanguo.h>
inherit SWORD;
inherit M_VALUE;
void setup() {
    set_adj("����");
    set_unit("��");
    set_id("dart", "ذ��");
	add_id("bishou");
    set_weapon_class(5);
    set_size(MEDIUM);
    set_value(5);
	set_currency_type("silver");
    set_wield_message("$N�γ�$o�����ٺ١��ظ�Ц��������\n");
    set_unwield_message("$N�ߵ�һ������$o���˻�ȥ��\n");
}

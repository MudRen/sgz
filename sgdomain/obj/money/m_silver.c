// by fire on Dec 11 1997 m_silver.c Ǯ
#include <sanguo.h> 
inherit M_MONEY;
void setup() {
    merge_setup();
    set_id("silver", "����");
    set_unit("��");
    add_id("money");
    set_m_rate(100);
    set_m_num(1);
    set_is_keeping(1);
    set_size(VERY_SMALL);
}

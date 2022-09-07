#include <sanguo.h> 
inherit M_MONEY;
void setup() {
    merge_setup();
    set_id("coin", "г╝");
    set_unit("нд");
    add_id("money");
    set_m_rate(1);
    set_m_num(1);
    set_is_keeping(1);
    set_size(VERY_SMALL);
}

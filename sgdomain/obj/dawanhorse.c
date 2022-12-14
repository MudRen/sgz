#include <sanguo.h>
#include "/wiz/ljty/ljty.h"
inherit M_HORSE_1;
inherit M_VALUE;
void setup()
{
    set_id("dawanhorse", "大宛马");
    add_id("dawan");
    add_id("horse");
    add_id("ma");
    set_relations("on");
    set_unit("匹");
    set_long("这是一匹白色的大宛马，生得龙颈狮鬃，四蹄飞青，似乎是匹好马。");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
    set_in_room_desc("大宛马(dawanhorse)");
    set_value(200);
    set_currency_type("silver");
    set_attack_ablity(100);
    set_defence_ablity(100);
    set_attack_power(20);
}

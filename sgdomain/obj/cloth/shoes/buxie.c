#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
inherit M_VALUE;
void setup()
{
    ::mudlib_setup();
    set_unit("˫");
    set_id("buxie", "��Ь");
    add_id("shoes", "xie");
    set_in_room_desc("��Ь(buxie)");
    set_long("һ˫����ͨͨ�Ĳ�Ь��");
    set_gettable(1);
    set_slot(FEET);
    set_wearmsg("$N����һ˫$o��\n");
    set_removemsg("$N����һ˫$o�����ֿĵ�Ь�׵�������\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(0);
}

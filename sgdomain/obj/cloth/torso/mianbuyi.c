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
        set_unit("��");
        set_id("mianbuyi","�޲���");
        add_id("mian", "cloth");
        set_in_room_desc("�޲���(buyi)");
        set_long("һ���������·������������������ů��");
        set_gettable(1);
        set_slot(ARMORS);
        set_wearmsg("$N����һ���޲��¡�\n");
        set_removemsg("$N��ȥһ���޲��¡�\n");
        set_attack_ability(-2);
        set_defence_power(0);
        set_defence_ability(-2);
        set_rongmao(0);
}

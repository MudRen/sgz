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
    set_id("hechang", "���");
    add_id("he chang");
    set_in_room_desc("���(hechang)");
    set_long("һ�����ĺ�멣������������ɷ���ǡ�");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N����$o������ȥ�ɷ���ǣ�������ʿ�緶��\n");
    set_removemsg("$N����һ��$o��\n");
    set_attack_ability(0);
    set_defence_power(1);
    set_defence_ability(0);
    set_rongmao(1);
    set_value(1);
    set_currency_type("silver");
}

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
    set_id("xiupao", "����");
    add_id("pao");
    set_in_room_desc("����(xiupao)");
    set_long("һ���������Ƶĳ��ۣ�ͼ����������ż�ֵ���ưɡ�");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N����$o��һʱ�����Ǳ����á�\n");
    set_removemsg("$N����$o��\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver");
}

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
    set_id("kaijia", "ϸ����");
    add_id("armor", "jia");
    set_in_room_desc("ϸ����(kaijia)");
    set_long("һ��ϸ���ף���̵����ɣ������·���Ҳ�����������ڷ�����á�");
    set_gettable(1);
    set_slot(ARMORS);
    set_wearmsg("$N����$o���������� �����ú���\n");
    set_removemsg("$N����һ��$o��\n");
    set_attack_ability(-4);
    set_defence_power(20);
    set_defence_ability(-2);
    set_rongmao(0);
    set_value(80);
    set_currency_type("silver");
}

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
    set_id("jinpao", "����");
    add_id("pao");
    set_in_room_desc("����(jinpao)");
    set_long("һ�����ۣ����������ü��õĽ������ģ�������������ͼ���������Ǹ��������֪��ʲô������");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N����һ��������$o��ϵ��һ�������\n");
    set_removemsg("$NС�ĵؽ⿪���������$o��\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(1);
    set_value(1);
    set_currency_type("gold");
}

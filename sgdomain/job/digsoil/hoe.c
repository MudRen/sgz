// by fire on Jan 9 1998 hoe.c
#include <ansi.h>
inherit M_WEAPON;
inherit M_DIGGER;
inherit M_INPUT;
inherit M_VALUE;
void setup() {
    set_adj("�ֱ���");
    set_id("chu tou", "��ͷ","hoe");
    set_unit("��");
    set_in_room_desc("һ��ũ�ҳ��صĳ�ͷ(chu tou)��");
    set_long("һ��ũ�ҳ��صĳ�ͷ(chu tou)��\n");
    set_attack_ability(2);
    set_attack_power(10);
    set_defence_ability(10);
    set_combat_messages("combat-hammer");
    set_value(1);
    set_currency_type("silver");
}

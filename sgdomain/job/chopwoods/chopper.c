// by row
#include <ansi.h>
inherit M_WEAPON;
inherit M_CHOPPER;
inherit M_INPUT;
void setup() {
    set_adj("�⼣�߰ߵ�");
    set_id("chopper", ""+YEL+"����"+NOR+"","kanchai dao");
    set_unit("��");
    set_in_room_desc("һ��Ѱ��ũ�����������"+YEL+"����"+NOR+"(kanchai dao)��\n");
    set_long("һ���⼣�߰ߵĿ��񵶡�\n");
    set_attack_ability(2);
    set_attack_power(10);
    set_defence_ability(10);
    set_combat_messages("combat-blade");
   set_is_keeping(1);
   set_size(5);
}

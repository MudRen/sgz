//by jiezhao on Dec 25 1997 jiubian.c �Žڱ�
#include <sanguo.h>
inherit SWORD;
inherit M_VALUE;
void setup()
{
set_adj("�Ž�");
set_unit("��");
set_id("whip", "��");
add_id("bian");
set_long("һ���������ƵľŽڱޣ��䲻��������������ˡ�");
set_in_room_desc("�Žڱ�(whip)");
set_weapon_class(5);
set_size(MEDIUM);
set_value(10);
set_currency_type("silver");
}
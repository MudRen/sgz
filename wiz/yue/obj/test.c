//by jiezhao on Dec 25 1997 mubang.c ľ��
#include <sanguo.h>
#include "/include/weapon.h"
inherit SWORD;
inherit M_VALUE;
void setup()
{
set_adj("ľ");
set_unit("��");
set_id("mu bang", "��");
add_id("bang");
add_id("mubang");
set_long("һ��������ľ�����Ѿ������ˡ�");
set_in_room_desc("ľ��(mu bang)");
set_weapon_class(5);
set_size(MEDIUM);
set_value(5);
set_currency_type("silver");
}

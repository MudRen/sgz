//by jiezhao on Dec 25 1996 madao.c ��
#include <sanguo.h>
inherit SWORD;
inherit M_VALUE;
void setup()
{
set_adj("��");
set_unit("��");
set_id("ma dao", "��");
add_id("blade");
add_id("dao");
add_id("madao");
set_long("һ������ǳ��õ��䵶�����滹��δ�ɵ�Ѫ��");
set_in_room_desc("��(ma dao)");
set_weapon_class(5);
set_size(MEDIUM);
set_value(10);
set_currency_type("silver");
}
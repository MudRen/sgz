//by jiezhao on Dec 25 1996 changjian.c ����
#include <sanguo.h>
inherit SWORD;
inherit M_VALUE;
void setup()
{
set_adj("��");
set_unit("��");
set_id("changjian", "��");
add_id("sword");
add_id("jian");
add_id("chang jian");
set_long("һ�������ĳ��������ŵ�㺮��");
set_in_room_desc("����(changjian)");
set_weapon_class(5);
set_size(MEDIUM);
set_value(10);
set_currency_type("silver");
}
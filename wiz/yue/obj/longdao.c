//by jiezhao on Dec 25 1997 longdao.c �������µ�
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit SWORD;
inherit M_VALUE;

void setup()
{
set_adj(HIC+"��������"+NOR);
set_unit("��");
set_id("yanyue blade", HIC+"��"+NOR);
add_id("blade");
add_id("dao");
set_long("����ǹ����õı������������һ�����Ĺ��֣�");
set_in_room_desc(HIC+"�������µ�"+NOR+"(yanyue blade)");
set_weapon_class(75);
set_size(LARGE);
set_value(5000);
set_currency_type("gold");
set_wield_message("ֻ������һ����$N�����ж���һ��"+HIC+"�������µ�"+NOR+"��\n");
set_unwield_message("$N��Ѫ�����"+HIC+"�������µ�"+NOR+"������䡣");
}

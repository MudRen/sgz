#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_WEAPON;
inherit M_VALUE;
void setup()
{
set_unit("��");
set_id("tiejishe mao", WHT+"������ì"+NOR);
add_id("tiejishe mao");
add_id("tiejishe");
add_id("mao");
set_in_room_desc(WHT+"������ì"+NOR+"(tiejishe mao)");
set_long("�����������֮���ű�����ȫ��һ�����ߣ�ì������
�����ɣ���������״��\n");
set_size(MEDIUM);
set_value(-1);
set_currency_type("gold");
set_attack_ablity(140);
set_attack_power(115);
set_defence_ablity(140);
set_combat_messages("combat-ji");
set_wield_message("$N˫��һ�ڣ����$o��������ǰ���������ˡ�\n");
set_unwield_message("$N����һ̧�����ѽ�����$o�����ͷ��\n");
}
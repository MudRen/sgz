// jueyinghorse.c by ljty 1998.03.29
#include <sanguo.h>
#include <ansi.h>
#include "/wiz/ljty/ljty.h"
inherit M_HORSE_1;
inherit M_VALUE;
void setup()
{
  set_id("jueyinghorse", HIW+"��Ӱ��"+NOR);
  add_id("jueying");
  add_id("horse");
  add_id("ma");
  set_relations("on");
  set_unit("ƥ");
  set_long("���Ǻ���ة��ܲٵ��İ��������ٶ�֮�쿰�ƾ�Ӱ");
  set_size(MEDIUM);
  set_value(-1);
  set_currency_type("gold");
    set_attack_ability(190);
    set_defence_ability(190);
    set_attack_power(60);

  set_max_capacity(VERY_LARGE*2);
  // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
  set_in_room_desc(HIW+"��Ӱ��"+NOR+"(jueyinghorse)");
set_get_on_msg("$N����Ծ��"HIW+"��Ӱ��"+NOR+"��"HIW+"��Ӱ��"+NOR+"�����ٵأ��͵����𣬾�Ҫ��ǰ�����\n");
set_get_off_msg("$Nһ��������"HIW+"��Ӱ��"+NOR+"����ǰ�룬$N����Ծ��"HIW+"��Ӱ��"+NOR+"��\n");
}
string get_arrival_msg()
{
  return get_riders_as_string()+"����"HIW+"��Ӱ��"+NOR+"������Ƶ����˹�����\n";
}
string get_departure_msg()
{
  return get_riders_as_string()+
"����һ��"HIW+"��Ӱ��"+NOR+"��ֻ��"HIW+"��Ӱ��"+NOR+"ˢ��һ����ǰԾȥ��ת�۱�û����Ӱ��\n";
}


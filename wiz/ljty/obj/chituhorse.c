// chituhorse.c by ljty 1998.03.29
#include <sanguo.h>
#include <ansi.h>
inherit M_HORSE;
inherit M_VALUE;
void setup()
{
  set_id("chituhorse", HIR+"������"+NOR);
  add_id("chitu");
  add_id("horse");
  add_id("ma");
  set_relations("on");
  set_unit("ƥ");
  set_long("��������µ�һ��Գ��������쳣������ν�������������г���
");
  set_size(MEDIUM);
  set_value(-1);
  set_currency_type("gold");
    set_attack_ability(200);
    set_defence_ability(200);
    set_attack_power(70);

  set_max_capacity(VERY_LARGE*2);
  // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
  set_in_room_desc(HIR+"������"+NOR+"(chituhorse)");
set_get_on_msg("$N����Ծ��"HIR+"������"+NOR+"��"HIR+"������"+NOR+"��˻һ���������������������ɡ�\n");
set_get_off_msg("$N�͵�һ��������"HIR+"������"+NOR+"ǰ�ȼ�̧��ž��һ��ֹס������$N����Ծ��"HIR+"������"+NOR+"��\n");
}

string get_arrival_msg()
{
  return get_riders_as_string()+ "����"HIR+"������"+NOR+"������Ƶ����˹�����\n";
}
string get_departure_msg()
{
  return get_riders_as_string()+
"����һ��"HIR+"������"+NOR+"��ֻ��"HIR+"������"+NOR+"һ��������������һ�ŵأ������Ƽ�������Զ����ȥ��\n";
}

inherit MONSTER;
inherit M_BLOCKEXITS;
inherit M_WANDER;

void setup() {

    set_name("Long", "��������С��");
    set_id("dragon", "Long");
    set_gender(1);
    set_proper_name("��������С��");
    set_in_room_desc("��������С��(Long)");
    set_long("����ô���������Ǻ�Σ�յ��¡�");

    set_max_hp(300);
  set_movement_time(5);
set_wander_area("wiz_area");

}

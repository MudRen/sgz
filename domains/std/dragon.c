// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit MONSTER;
inherit M_BLOCKEXITS;
inherit M_WANDER;

void setup() {

    set_name("Tiamat", "������");
    set_id("dragon", "troll");
    set_gender(1);
    set_proper_name("����������");
    set_in_room_desc("����������(Tiamat)");
    set_long("����ô���������Ǻ�Σ�յ��¡�");

    set_max_hp(300);
  set_movement_time(5);
set_wander_area("wiz_area");

}


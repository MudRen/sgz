// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit MONSTER;
inherit M_BLOCKEXITS;

void setup() {
    object sword;

    set_name("bill", "�ȶ�");
    set_id("troll");
    set_gender(1);
    set_proper_name("����ȶ�");
    set_in_room_desc("����ȶ�");
    set_long("����ͨ��������յúܽ�ȥ�۲�������ˡ�");
    set_max_hp(10);

    add_block("north");
    set_block_action("$N1��$o�ߣ�ȴ��$N��ס��$p1·��\n");

    sword = new("/domains/std/objects/sword");
    sword->move(this_object());
    do_wield(sword);
}

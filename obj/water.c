// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINKABLE;

create() {
  ::create();
  set_proper_name("ˮ");
  set_in_room_desc("������һ̲ˮ��");
//  set_weight(4);
  set_adj( "һЩ", "һƬ", "һ̲" );
  set_id( "water", "liquid", "h2o" );
  set_long("��ˮ������ûʲô�ر�ġ�\n");
  set_gettable("�����Էŵ��ʲô��ȥ...\n");
  set_droppable("���԰�������ʲô������...\n");
}

int move_water(object target) {
    if (present("water", target)) {
        write(target->short()+"������������ˮ��\n");
        return 0;
    }
    move(target);
    return 1;
}

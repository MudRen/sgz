// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit OBJ;
inherit M_GETTABLE;

void setup()
{
    set_adj("С", "������");
    set_unit("��");
    set_id("key", "Կ��");
    set_in_room_desc("һ���������ı��չ�Կ�ס�");

    set_gettable(1);
    set_long("����һ�����������չ��Կ�ס�\n");
}

mixed key_type()
{
    return "skeleton";
}

int indirect_unlock_obj_with_obj() {
    return 1;
}

int indirect_lock_obj_with_obj() {
    return 1;
}
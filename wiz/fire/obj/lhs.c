// �ϻ���
// lhs.c
#include <mudlib.h>
#include <sanguo.h>
inherit OBJ;
inherit M_CLIMBABLE;
void setup() {
    set_unit("��");
    set_id("tree","�����ϻ���");
    set_long("һ�ñ�����ɣ�İ����ϻ�����������������(climb)��\n");
    set_in_room_desc("һ�ð����ϻ���(tree)\n");
    set_up_destination(FROOMPATH+"vhuaishu_shang");
}

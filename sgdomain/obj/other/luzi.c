// by fire on Jan 9 1998 luzi.c
#include <ansi.h>
inherit OBJ;
void setup() {
    set_adj("���ص�");
    set_id("luzi", "¯��","fire");
    set_unit("��");
set_in_room_desc("һ��ũ���շ���¯�ӣ�����ð�ź���"+HIR+"¯��(fire)"+NOR+"��");
    set_long("һ��ũ���շ���¯�ӣ�����ð�ź���"+HIR+"¯��(fire)"+NOR+"��\n");
}
int can_light_the_magic_torch() {
    return 1;
}
mixed indirect_light_obj_with_obj() {
    return 1;
}

// by row on June 1999 xianglu.c
#include <ansi.h>
inherit OBJ;
void setup() {
    set_adj("С�ɾ��µ�");
    set_id("xianglu", "��¯");
    set_unit("ֻ");
set_in_room_desc("���ϰ���һֻС�ɾ��µ�"+RED+"��¯"+NOR+"(xianglu)������������Щ"+HIR+"����"+NOR+"��\n");
set_long("����һֻС�ɾ��µ�"+RED+"��¯"+NOR+"������������Щ"+HIR+"����"+NOR+"��\n");
}
int can_light_the_magic_torch() {
    return 1;
}
mixed indirect_light_obj_with_obj() {
    return 1;
}

// by row
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_MERGEABLE;
void setup() {
merge_setup();
    set_id("pork", "%^B_WHITE%^%^H_RED%^������%^RESET%^","zhuleipai");
    set_unit("��");
    set_in_room_desc("һ���е����������%^B_WHITE%^%^H_RED%^������%^RESET%^(pork)��\n");
    set_long("����һ��ո���������%^B_WHITE%^%^H_RED%^������%^RESET%^���������룬ɫ�ʾ�ѡ�\n");
    set_size(VERY_SMALL);
	set_ori_size(VERY_SMALL);
     set_can_drop(0);
     set_can_drop("ι����������������Ҫ�����ģ�С�����ĵ�����\n");
     set_can_give(0);
}

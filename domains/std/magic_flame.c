// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;

void setup() {
    set_adj("��ɫ��");
    set_id("flame", "����", "fire");
    set_unit("��");
    set_in_room_desc("һ����ɫ�Ļ���(flame)�������������š�\n");
    set_long("�����ǿ���������ȼ�գ��ƺ��ǳ���ĳ��ħ����\n");
}

int can_light_the_magic_torch() {
    return 1;
}

mixed indirect_light_obj_with_obj() {
    return 1;
}


// mutong.c "��ͯ"
#include <mudlib.h>
inherit LIVING;
inherit M_ITEMS;

void setup() {
    set_name("boy", "��ͯ");
    set_gender(1);
    set_proper_name("С��ͯ");
    set_in_room_desc("��ţ��С��ͯ(boy)");
    set_long("С��ͯ��������������ϻ�ţ���ϣ��ò�ñ����̫��������ʱ��ʱ��Ū��һ���̵ѡ�");

    add_item("�̵�", "flute", "duan di",
		([ "look" : "һ�����ƵĶ̵ѡ�",
		]) );
    add_item("��ñ", "hat", "caomao",
                 ([     "look" : "һ���Ʋ�ñ��",
                        "get" : "��ȡ��������",
                 ]) );
}

// ������ note.c by benben
#include <mudlib.h>
#include <sanguo.h>
inherit OBJ;
inherit M_READABLE;
void setup() {
    set_unit("��");
    set_id("note","������");
    set_long("������д�ţ��Ҳ��ڼң�����������ѵ��ȥ�ˣ��������ͻ�����
 ����дemail���ҡ�\n");
    set_in_room_desc("���϶���һ��������(note)\n");
}

// by fire on Dec 11 1997 m_silver.c Ǯ
// m_homekey.c
#include <sanguo.h> 
inherit OBJ;
inherit M_GETTABLE;

private string m_owner;
void setup()
{
    set_adj("С", "������");
    set_unit("��");
    set_id("key", "Կ��");
    set_in_room_desc("һ����������Կ�ס�");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_is_keeping(1);
    add_save(({"m_owner"}));
}
void set_owner(string owner) {
    m_owner=owner;
}
string long() {
	return "����һ��������"+CHAR_D->get_char(m_owner,"name")+"�ҵ�Կ�ס�\n";
}
mixed key_type()
{
    return m_owner;
}

int indirect_unlock_obj_with_obj() {
    return 1;
}

int indirect_lock_obj_with_obj() {
    return 1;
}
int not_give_npc() {
	return 1;
}
// tiezi.c by fire on May 27, 1999
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
void setup()
{   
    set_id("tiezi", "%^YELLOW%^�ż���%^RESET%^");
    add_id("zhan_jishaoxin");
    set_long("�ż����е����ӣ��������ɻ������ļҶ���\n");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_unit("��");
    set_can_drop(0);
    set_can_give(0);
    set_is_keeping(1);
}

// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;

void setup()
{
    set_id("��ͼ");
    set_unit("��ͼ");
    set_long("ͼ��������ʲݵ��ּ���");
    set_flag(ATTACHED);
    set_gettable("���ͼ�����ε�������ǽ�ϡ�");
    set_size(SMALL);
}




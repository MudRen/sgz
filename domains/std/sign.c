// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit OBJ;
inherit M_READABLE;
inherit M_GETTABLE;

void setup()
{
    set_id("sign", "����");
    set_unit("��");
    set_gettable(0);

    set_in_room_desc("һ��С����(sign)�����ڰ���С�");

    set_long("�����ö���(read)���������\n"); 
    set_text( @ENDMARKER
��ӭ���� LIMA Mudlib���Ĵ����߰��㣬��������...
ENDMARKER );   

}


// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

void setup()
{
set_area("wiz_area");
    set_brief("������");
    set_long(
        "�����Ǳ����ꡣ��ҵ���������������̽�յ�ս��Ʒ�͹�������Ķ�����\n"
        "ǽ������һ����ʾ(sign)��\n"
        );

    add_item("sign", ([
"look" : "���� biff ���� (swords, keys, etc),\n"
         "  �� biff ���� (sword or sword #)\n"          
         "  �� biff ���� (sword, first sword etc)\n",
"read" : "���� biff ���� (swords, keys, etc),\n"
         "  �� biff ���� (sword or sword #)\n"
                  "  �� biff ���� (sword, first sword etc)\n",
        ]) );
    set_objects( (["/domains/std/shopkeeper.c" :1,
        STAIRS : ({ 1, "/domains/std/wizroom" }),
        ]) );

    set_exits( ([ "up" : "wizroom" ]) );
}

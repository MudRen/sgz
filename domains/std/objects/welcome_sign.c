// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit SIGN;

void setup()
{
    set_unit("��");
    set_adj("С", "�ƾɵ�");

    set_in_room_desc("������һ��С��ʾ�ƣ�����ز���ɳ���ϡ�");

    set_long("�����ʾ�ƺ��ƾ��ˣ���������ֻ���ǿ���Զ�һ����\n"); 
    set_text( @ENDMARKER

Warning:

DON'T USE THIS AREA ON YOUR MUD!!!

This area is going to be used (ever so slightly changed) by a mud the LIMA 
guys are making.  We are providing this area as an example only!  You can 
use the code to the extent that you want to code something similar by 
example, but therwise, get your own ideas =P

As for this area, if you want to play it before you read the code, there are
nine rooms and a treasure to find.  See if you can do it...

-- The LIMA guys.
ENDMARKER );   

}


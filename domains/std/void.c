// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit INDOOR_ROOM;


void setup(){

    /* ensure this place is lit, regardless of DEFAULT_LIGHT_LEVEL */
    set_light(1);
    set_brief("������������");
    set_long("Ŷ�������������ˣ����治�ң��ֵ��������ˡ�");
        set_exits( ([
        "out" :  START,
        ]) );
}
int is_voidroom()
{
  return 1;
}

// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit NON_ROOM;

void setup(){
    set_area("wiz_area");
    set_brief("������");
    set_long("�����ǹ����ݣ�����ʦ��ҫ���Եĳ���ĳ�����������ȥ�Ǵ�����");
    set_exits( ([
                 "north" : "wizroom.c"
    ]) );
    set_objects(([ "/domains/std/guild_guard" : ({ "stock-mage" }) ]));
}



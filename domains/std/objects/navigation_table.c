// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CONTAINER;

void
setup() {
    
    set_id("table", "����");
    set_adj("Сľͷ");
    set_long("����һ�����߿��С�������а�����������������ȡ�");
    set_flag(ATTACHED);
    set_preposition("on");
    set_size(LARGE);
    set_objects( ([
                   "/domains/std/objects/shovel" : 1,
                   ]) );
}

            

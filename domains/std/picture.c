// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;

void setup()
{
    object ob;

    set_unit("��");
    set_id("picture", "�Ż�");
    set_gettable(1);
    if ( (ob = this_body()) && (ob = environment(ob)) ) {
        set_long("�㳯���Ͽ�ȥ��������\n\n" + ob->long());
        add_save( ({ "long" }) );
    }
}


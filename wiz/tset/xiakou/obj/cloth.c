//  cloth.c
//  ����
//  created by tset 1/16/98
//  last updated by tset 1/26/98

#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>

inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;

void setup()
{
        ::mudlib_setup();
        set_unit("��");
        set_id("cloth", "����", "buyi");
        set_in_room_desc("һ������(cloth)");
        set_gettable(1);
        set_slot(TORSO);
        set_is_keeping(1);   
}

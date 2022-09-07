//  jia.c
//  Ìú¼×
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>

inherit M_VALUE;
inherit M_GETTABLE;
inherit M_WEARABLE;   
inherit M_DAMAGE_SINK;

void setup()
{
        ::mudlib_setup();
        set_unit("¼þ");
        set_id("armor", "Ìú¼×", "jia"); 
        set_in_room_desc("Ìú¼×(armor)");
        set_gettable(1);
        set_slot(TORSO);
        set_value(30);
        set_currency_type("silver");
}

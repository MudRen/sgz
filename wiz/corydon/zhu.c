//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_VALUE;
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("��");
set_id("zhu", HIY+"���������"+NOR);
set_in_room_desc(HIY+"���������(zhu)"+NOR);
set_gettable(1);
set_slot(HEAD);
    set_currency_type("gold");
    set_value(5);
}

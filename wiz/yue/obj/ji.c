#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit SWORD;
inherit M_VALUE;
void setup()
{    set_id("ji", HIG+"���컭�"+NOR);
set_in_room_desc(HIG+"���컭�"+NOR+"(ji)");
set_weapon_class(25);
set_size(MEDIUM);
set_value(20);
set_currency_type("silver");
}

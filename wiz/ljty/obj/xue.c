//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
void setup()
{
::mudlib_setup();
set_unit("˫");
set_id("xue", HIB+"��ͷ����ѥ"+NOR);
set_in_room_desc(HIG+"��ͷ����ѥ(xue)"+NOR);
set_gettable(1);
set_slot(FEET);
}

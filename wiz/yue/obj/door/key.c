//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_GETTABLE;
inherit OBJ;
void setup()
{
set_unit("°Ñ");
set_id("key", "½ğÔ¿³×");
set_in_room_desc("½ğÔ¿³×(key)");
set_gettable(1);
}

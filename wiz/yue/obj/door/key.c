//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit M_GETTABLE;
inherit OBJ;
void setup()
{
set_unit("��");
set_id("key", "��Կ��");
set_in_room_desc("��Կ��(key)");
set_gettable(1);
}

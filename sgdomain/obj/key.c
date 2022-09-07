#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>

inherit M_GETTABLE;
inherit OBJ;

private string key_type = "changan_dong";

void setup()
{
  set_unit("°Ñ");
   set_id("key","½ğÔ¿³×");
  set_in_room_desc("½ğÔ¿³×(key)");
  set_gettable(1);
}

string query_key_type()
{
  return key_type;
}

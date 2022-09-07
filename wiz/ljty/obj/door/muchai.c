#include <sanguo.h>
#include "/wiz/ljty/ljty.h"
#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_USEABLE;

private string xiufu_type;

void setup()
{
  set_unit("畝");
  set_id("muchai","直可");
  set_in_room_desc("直可(muchai)");
  set_num_uses(3);
  set_gettable(1);
}

string query_xiufu_type()
{
  return xiufu_type;
}
void set_xiufu_type(string type)
{
  xiufu_type = type;
}
string xiufu_type()
{
  return "muchai";
}


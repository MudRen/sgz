#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>

inherit M_GETTABLE;
inherit OBJ;

public string key_type;

void setup()
{
  set_unit("��");
   set_id("key","����Կ��");
  set_in_room_desc("����Կ��(key)");
  set_gettable(1);
}

string query_key_type()
{
  return key_type;
}
void set_key_type()
{
  key_type = "changan_xi";
}
string key_type()
{
  return "changan_xi";
}

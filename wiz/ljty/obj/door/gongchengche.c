#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>

inherit OBJ;

public string chuang_type;

void setup()
{
  set_unit("��");
   set_id("gongchengche","���ǳ�");
  set_in_room_desc("���ǳ�(gongchengche)");
}

string query_chuang_type()
{
  return chuang_type;
}
void set_chuang_type()
{
  chuang_type = "gongchengche";
}
string chuang_type()
{
  return "gongchengche";
}

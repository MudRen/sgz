//by chun 
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit OBJ;
void setup()
{
  set_id("roses", HIR+"玫瑰"+NOR);
  set_long("一簇娇艳的玫瑰，这异香而有刺的玫瑰你还是不要采吧(zhe)。\n");
  set_size(VERY_SMALL);
  set_in_room_desc("一簇娇艳的"+HIR+"玫瑰"+NOR+"(roses)");
  }

int smell() {
  write("这玫瑰散发着醉人的异香。\n");
  return 1;
}

int zhe(string n) {
  object o_rose;
  this_body()->simple_action("$N忍不住摘下一朵玫瑰。\n");
  if (!random(5)) {
  	this_body()->simple_action("$N不小心让玫瑰扎了一下，好疼。\n");
  	this_body()->set_cur_hp(0);
  }
  o_rose=new("/wiz/chun/rose.c");
  o_rose->get();
  o_rose->move(this_body());
  return 1;
 }
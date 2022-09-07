#include <mudlib.h>
#include <setbit.h>
#include <sanguo.h>
inherit COMPLEX_CONTAINER;
inherit M_GETTABLE;
inherit M_LOCKABLE;
inherit M_OPENABLE;
void setup(){
  object ob;
  set_in_room_desc("食品柜(foodgui)。");
  set_id( "foodgui","食品柜", );
  add_id("gui");
  set_long("\n这是一个大大的食品柜，里面一定有许多好吃的。赶快打开吧。\n");
  set_relations("in");
  set_max_capacity(SMALL*2);
  ob=new("/wiz/ljty/obj/ljtycandy.c");
  ob->move(this_object());
}

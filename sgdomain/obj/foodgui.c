#include <mudlib.h>
#include <setbit.h>
#include <sanguo.h>
inherit COMPLEX_CONTAINER;
inherit M_GETTABLE;
inherit M_LOCKABLE;
inherit M_OPENABLE;
void setup(){
  object ob;
  set_in_room_desc("ʳƷ��(foodgui)��");
  set_id( "foodgui","ʳƷ��", );
  add_id("gui");
  set_long("\n����һ������ʳƷ������һ�������óԵġ��Ͽ�򿪰ɡ�\n");
  set_relations("in");
  set_max_capacity(SMALL*2);
  ob=new("/wiz/ljty/obj/ljtycandy.c");
  ob->move(this_object());
}

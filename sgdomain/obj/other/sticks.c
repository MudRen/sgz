// attacted sticks astick.c
#include <mudlib.h>
#include <sanguo.h>
inherit OBJ;
void setup() {
    
    set_id("sticks", "一些树枝");
    set_long("一些很有弹性的槐树枝，看来可以当武器。试试折一根下来。(zhe sticks)\n");
    set_in_room_desc("一些槐树枝(sticks)");
    set_size(VERY_SMALL);
}
int zhe(string n)
{
  	object o_stick;
	this_body()->simple_action("$N折下一根槐树枝，挥舞了两下，插入腰间。\n");
        o_stick=new(__DIR__+"stick.c");
	o_stick->get();
	o_stick->move(this_body());
  return 1;
}

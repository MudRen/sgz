// attacted sticks astick.c
#include <mudlib.h>
#include <sanguo.h>
inherit OBJ;
void setup() {
    
    set_id("sticks", "һЩ��֦");
    set_long("һЩ���е��ԵĻ���֦���������Ե�������������һ��������(zhe sticks)\n");
    set_in_room_desc("һЩ����֦(sticks)");
    set_size(VERY_SMALL);
}
int zhe(string n)
{
  	object o_stick;
	this_body()->simple_action("$N����һ������֦�����������£��������䡣\n");
        o_stick=new(__DIR__+"stick.c");
	o_stick->get();
	o_stick->move(this_body());
  return 1;
}

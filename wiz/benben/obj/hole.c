//С�� hole.c by benben 

#include <size.h>

inherit CONTAINER;
inherit M_DIGGABLE;
void
setup()
{

    set_id("hole","С��");
    set_long("�������￴�˿�������������ʲô�����أ�\n");
    set_size(MEDIUM);
    set_max_capacity(LARGE);
}


void change_desc(string s)
{                             
 set_in_room_desc(s);
}

void change_max_capacity(int x)
{
  set_max_capacity(x);
}                                                
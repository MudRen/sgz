// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <size.h>

inherit CONTAINER;

void
setup() 
{
    
    set_id("С��");
    set_long("�����û��ʲô����ġ�\n");
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

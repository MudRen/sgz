// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;


void setup() 
{
  set_area("pirate");
  set_brief("��б�ص�");

  set_long("����ʲôҲû�С�\n");
  set_light(0);
  set_exits( ([
               "south" : "inside_cave",
               ]) );
  set_hidden_exits();
  set_default_exit ("�Ǳ�û�г��ڡ�\n");

  set_objects( ([

                 ]) );
}



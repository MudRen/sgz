// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Beek - a simple room to demonstrate relationships and some toys

#include <mudlib.h>

inherit ROOM;

void setup() {
  set_area("wiz_area");
    
    set_brief("Relations and Toys");
    set_long("������һ����Է��������ǵ�һ����Է���������һ����ɭɭ"
	     "�Ķ�Ѩ������������������ڸı䡣");
    set_exits( ([ "north" : "example_room1", "east" : "room4" ]) );
    set_objects( ([
		   "/domains/std/harry" : 1
		   ]) );
}


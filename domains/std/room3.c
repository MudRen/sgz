// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

 /* Do not remove the headers from this file! see /USAGE for more info. */
  
    // Beek - a simple room to demonstrate relationships and some toys
  
#include <mudlib.h>
  
inherit ROOM;
  
void setup()
{
    set_brief("���׵�ɽ��");
    set_long("��վ�ڰ��׵�ɽ�����ֻ��������ռ���ߡ�");
    set_exits( ([ "north" : "room2" ]) );
    set_objects( ([
	"/domains/std/barney" : 1
	]) );
}

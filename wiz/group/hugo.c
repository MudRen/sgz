//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
   set_light(50);
   set_brief(""+YEL+"�ʹ�"+NOR+"");
   set_long("    �����ǻʹ�����������������ǰ�߹���ʹ�㲻����̾���Ͼ�Ȼ
��������������ˡ����ǻʹ���\n\n");
   set_exits( ([
	     "north" : __DIR__+"dadi.c",
	     "south" : "/sgdomain/area/cities/changan/ca_bcm.c"
	]) );
}

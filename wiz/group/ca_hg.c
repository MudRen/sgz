//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
   set_area("changan");
   set_light(50);
   set_brief(""+YEL+"��"+NOR+"");
   set_long("    �����Ǻ󹬡���������������ǰ�߹���ʹ�㲻����̾���Ͼ�Ȼ
��������������ˡ����ǻʹ����������ڹ�����԰��\n\n");
   set_room_state("valid_start");
   set_exits( ([
             "east"  : __DIR__+"ca_yhy.c",
	     "south" : __DIR__+"ca_dd.c",
	     "west" : __DIR__+"ca_qg.c",	
	]) );
}

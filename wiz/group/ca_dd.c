//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;

void setup()
{
   set_area("changan");
   set_light(50);
   set_brief(""+YEL+"���"+NOR+"");
   set_long("    ����ǻʵ۵Ľ��ǵ��ȷ��ڻԻͣ�����Ŀ��Ͼ�ӣ���Χ��
�˶�Ŀ��б�ӣ��㲻�Խ��ľ���һ������ʹ�����Ҳ���ҳ�һ����
���ĵ�վ��һ�ԡ�\n\n");

   set_room_state("valid_start");
   set_exits( ([
	     "south" : __DIR__+"ca_hgdm.c",
	     "north" : __DIR__+"ca_hg.c",
	]) );
}

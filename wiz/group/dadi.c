//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;

void setup()
{
   set_area("changan");
   set_light(50);
   set_brief(""+YEL+"���ǵ�"+NOR+"");
   set_long("    ����ǻʵ۵Ľ��ǵ��ȷ��ڻԻͣ�����Ŀ��Ͼ�ӣ���Χ��
�˶�Ŀ��б�ӣ��㲻�Խ��ľ���һ������ʹ�����Ҳ���ҳ�һ����
���ĵ�վ��һ�ԡ�\n\n");

   set_exits( ([
	     "south" : __DIR__+"hugo.c",
	]) );
	set_objects( ([
        "/sgdomain/event/ev_king/king.c" : 1,
]));	
}

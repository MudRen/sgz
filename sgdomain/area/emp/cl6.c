#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"����"+NOR+"");
   set_long("
    ���ﱱ����һ������������Χ�в��ٵ���ǰ������Ѳ�ߡ�������
������վ��һ��С��ʿ����ִ������ľ�ޱ����վ�����������һ
����ʾ�����飺%^H_RED%^�������صأ�����������%^RESET%^�㲻�������ص�����һ����
�����˺���������
\n");
   set_exits( ([
             "north" : __DIR__+"ldf",
	     "south" : __DIR__+"cl5",
        ]) );
	set_objects( ([ __DIR__+"xds" : 1, ]));	}

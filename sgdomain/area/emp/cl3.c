#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"����"+NOR+"");
   set_long("
    ����ı�����ǻ������Ĺ��ĵ����鷿����Χ�д�����ɫ���ص�
��ǰ������Ѳ�ߣ��������Ľ䱸ɭ�ϡ����鷿���ſ�վ��һ��С̫
�࣬���޾���ɵش���վ����ǰ���ű���һ����Ŀ�ĸ�ʾ������д�ţ�
              %^H_RED%^���鷿�صأ��������룬����������%^RESET%^

");
   set_exits( ([
             "north" : __DIR__+"ysf",
	     "south" : __DIR__+"cl2",
        ]) );
	set_objects( ([ __DIR__+"xtj" : 1, ]));	}

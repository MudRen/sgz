#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"����"+NOR+"");
   set_long("
    ��һ·�ϵĶ��ǻ��ȣ�����һ����ͥԺ��԰��ֻ�����ܻ�ʣ���
���񻨣��㲻��������̾���ҹ��е������ݻ���һ�ӶӼ�����������
������Ѳ�ߣ�����С̫������ɫ�Ҵҵش�������߹�����֪��������
ʲô���������顣

");
   set_exits( ([
             "dadian" : __DIR__+"dadi.c",
	     "west" : __DIR__+"cl2",
        ]) );
}

// gate.c

#include <ansi.h>

inherit  OUTDOOR_ROOM;

void setup()
{
	set_area("death");
	set_light(2);
	set_brief(HIW "���Ź�" NOR);
	set_long("
�������������������ڡ����Źء���������ǰ������һ���ߴ��
��ɫ��¥�������������޿�������ж�ǰ������Ϊһ�����Źؾ���
���ٻ������ˡ�
");
  set_exits( ([
        ]) );
}
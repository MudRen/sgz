//  eastgate.c
//  �Ŀڶ���
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
	set_brief("����");
        set_long("
�����Ͼ������ϣ���ʱ����ʿ���ڳ�ǽ������Ѳ�ߡ�һ����������
����ǽ�ϡ���Щʿ�������̲�������ա���ȥ���ǽ��Ĵ�·�ˡ�
\n\n");

  set_exits( ([
        "west" : __DIR__"xiakoue",
	"east" : __DIR__"jxroad/0/3",
                ]) );

  add_item("sign", "����", "��",
                ([ "look" : "������д�š�"+YEL+"�Ŀ�"+NOR+"����",
                ]) );

}

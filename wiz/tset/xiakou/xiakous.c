//  xiakous.c
//  �Ŀڳ���
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("����");
        set_long("
����һƬ��Ȼ֮���������Ǹ����̣�ʱ�����������������û�����
�����ƺ���һ���������ſ��мҶ����ء��Ϸ����ϳ��š�
\n\n");

  set_exits( ([
        "north": __DIR__"xiakouc",
        "south": __DIR__"southgate",
        "east" : __DIR__"tiepu",
        "west" : __DIR__"jiangfu",
                ]) );
}

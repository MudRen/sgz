//  xiakoue.c
//  �ĿڳǶ�
//  created by tset 1/20/98
//  last updated by tset 1/20/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("�Ƕ�");
        set_long("
����һ����Ϊ���ֵĴ�֣���ЩС�궼������������и��ֿ⣬��   � 
�����������أ������Ǹ�Ҫ���ĵط����ϱ�ʱʱ����Щ�������� 
\n\n");

  set_exits( ([
        "north" : __DIR__"liangcang",
        "south" : __DIR__"bingying",
        "east"  : __DIR__"eastgate",
        "west"  : __DIR__"xiakouc",
                ]) );
 
}

//  xiakouw.c
//  �Ŀڳ���
//  created by tset 1/20/98
//  last updated by tset 1/20/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("����");
        set_long("
���������ĵģ�������ʲô���������������߾ͳ��������ţ�����  
�󽭰��ߡ� 
\n\n");

  set_exits( ([
        "east"  : __DIR__"xiakouc",
        "west"  : __DIR__"jianganw",
                ]) );
                
}               

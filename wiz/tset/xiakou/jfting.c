//  jfting.c
//  �Ŀڴ���
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;

void setup(){
        object door;
        set_area("xiakoujf");
        set_light(20);
        set_brief("����");
        set_long("
������ƻ�Ի͡����ϰ���һ���������Ա��кö���λ�����ٽ���
ıʿ����������۴��£����۲��ݡ�
\n\n");

  set_exits( ([
        "north": __DIR__"jiangfu"
                ]) );
}

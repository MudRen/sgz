//  jiangfu.c
//  �Ŀڽ���
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
�������������壬��ɢ����Щ���Ρ����ߺ��������ڴ����̣��ϱ�
�Ǹ����������ߵ�С����");
set_state_description( "jf_door_off", "���š�\n\n");
set_state_description( "jf_door_on", "���š�\n\n"); 

  set_exits( ([
        "north": __DIR__"jfzhang",
        "south": __DIR__"jfting", 
        "east" : __DIR__"xiakous",
        "west" : __DIR__"jfhou",  
                ]) );
                
  set_objects( ([
         __DIR__"obj/jf_door" : ({ "west" }),
                ]) );
                
  set_default_exit( "��ǽ��������������·�ĺá�\n");
  door = present( "door");
  if( !door->query_closed())
  door->do_on_open();
}

//  xiakouc.c
//  �Ŀڳ����� 
//  created by tset 1/16/98
//  last updated by tset 1/19/98   

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        object ob;
        set_area("xiakou");
        set_light(20);
        set_brief("������");
        set_long("
�Ŀ�����С�ǣ�ȴ�����վ���������Ǯ�����˽��Ŀ��ͱ��صء���
����ʿ����ҹѲ�ߣ���������ƽ��������
\n\n");

  set_exits( ([
        "north" : __DIR__"xiakoun",
        "south" : __DIR__"xiakous",
        "east"  : __DIR__"xiakoue",
        "west"  : __DIR__"xiakouw",
                ]) );
                
//        if(present("bing")) return;
        ob=new(__DIR__"npc/bing");
        ob->set_wander_area("xiakou");
        ob->set_movement_time(60);
	ob->move(this_object());
}

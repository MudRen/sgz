//  xiakoun.c
//  �ĿڳǱ�
//  created by tset 1/16/98
//  last updated by tset 1/19/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        object ob;

        set_area("xiakou");
        set_light(20);
        set_brief("�Ǳ�");
        set_long("
�������ĿڳǱ��������йٱ����ء������ż��ǽ����������и�С
��ջ������������ЪϢ��
\n\n");

  set_exits( ([
        "north" : __DIR__"jiangan",
        "south" : __DIR__"xiakouc",
        "east"  : __DIR__"xiakoukz",
                ]) );

//if(present("bing")) return;
        ob=new(__DIR__"npc/bing");
	ob->move(this_object());
}

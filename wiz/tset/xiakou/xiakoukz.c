//  xiakoukz.c
//  �Ŀ�С��ջ
//  created by tset 1/16/98
//  last updated by tset 1/19/98
 
#include <mudlib.h>

inherit INDOOR_ROOM;
inherit "/sgdomain/modules/m_store.c";

void setup(){
        set_area("xiakou");
        set_light(10);
        set_brief("С��ջ");
        set_long("
С��ջ�����ϰ�һ��û����ɵ����ӡ����濴�������ٿ��ˡ�ǽ��
�м������̣���������˯���ĵط��ˡ����߳�ȥ�����ĿڳǱ�����
���и���ۡ�
\n\n");
                        
    set_exits( ([
        "south" : __DIR__"macao",
        "west"  : __DIR__"xiakoun",
                ]) );

    set_objects( ([
         __DIR__"npc/malaoban" : 1,
                ]) );

  add_object( __DIR__"obj/maliao.c");
  add_object( __DIR__"obj/jiudai.c");
  add_object( __DIR__"obj/mianbing.c");

  add_item("dipu", "����",
        (["look" : "һ�ż򵥵ĵ��̣�����������˯����",
          "sleep" : "$N��ͷ��������һ�ɣ��Ϳ�ʼ������˯��"]) );

}


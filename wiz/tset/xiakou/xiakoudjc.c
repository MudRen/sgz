//  xiakoudjc.c
//  �Ŀڵ㽫��
//  created by tset 1/23/98
//  last updated by tset 2/1/98

#include <mudlib.h>
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("�㽫��");
        set_long("
�㽫���ڿտտ�������������һ���߸ߵĵ㽫̨���㽫̨��������
�������ڷ��������졣������һ�����ļ��⣬�����к�Щ���ˣ�
������Щ���������ϼලʿ��ѵ����
\n\n");

  set_exits( ([
        "west" : __DIR__"bingying",
                ]) );

  add_item("qi", "sign", "����", "��",
                ([ "look" : "�����ϴ���д�š�"+YEL+"��"+NOR+"����",
                   "get"  : "���õö���",
                ]) );

}


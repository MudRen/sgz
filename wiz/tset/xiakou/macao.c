//  macao.c
//  �Ŀ����
//  created by tset 1/19/98
//  last updated by tset 1/19/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(10);
        set_brief("���");
        set_long("
������һ����ۡ�ǽ�Ǳ���һ��ˮ�����ұ��м���ľ׮�������Ǹ�
С��ջ��
\n\n");

    set_exits( ([
        "north" : __DIR__"xiakoukz"
                ]) );

    set_objects( ([
        __DIR__"obj/well.c" : 1 ]) );

  add_item("wood", "ľ׮",
        (["look" : "����ľ׮��������˩��ġ�"]) );

  add_item("piao", "ˮư",
        (["look" : "һ������Ҩˮ��ˮư��"]) );
}


//��ͤ��

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup()
{
    set_area("nono_room");
    set_light(50);
    set_brief(""+HIW+"���� "+NOR+"");
    set_long(

"�����ã����϶����������ס������һ������������������ϸ������ǽ������һ����
�ң�����д�������֡��ҡ������а���һ��ɼľԲ���ͼ������ӣ�������һ�׾��µ�
���˴������Ҳ����һ�����ã��������ͻ���ɽ�����Ƕ�����ֱʡ����߲�Զ������
����");
    set_exits( (["up" : FROOMPATH+"vzhu_lin.c", 
                 "west" : "/wiz/nono/shufang.c",
 "out" : "/wiz/nono/fuyuan.c",
             ]) );

}
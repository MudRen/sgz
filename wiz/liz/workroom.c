#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;
void setup(){
    set_area("liz_room");
    set_light(50);
    set_brief(""+HIR+"������"+NOR+"��"+HIG+"��"+NOR+"");
    set_long(
"\n ���˹����,����ϴ����,�ִ�л����,��֮��Զ��,
��Ϧ������,��˭������,�������Ը�,����ο���. \n
�������������������������ˣ� 
ʲô���鶼���� ��˵�ɣ� :) \n
������еģ����Ӹ��ҵ���������! \n");    set_exits((["out" :  FROOMPATH+"vzhu_lin.c",]) );              
    set_objects (([ "/wiz/shaoyng/npc/jiangwei.c" : 1 ]));
}


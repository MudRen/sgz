// ����,marry_fang.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
    set_light(1);
    set_brief(""+HIR+"����"+NOR+"");
    set_long("
    ������Ƕ����ˡ����޵Ļ��򾲾���ȼ�ţ���ʱ����һ������
�������ź�������Բ���ϰ���һ���ƣ�����С�Ʊ������ź����ʵ�
��������������ı��졣��������������һ�����˵Ĵ��⡣
\n\n");
    set_exits( ([
        "out" : __DIR__+"marry_tang.c",
    ]) );
   set_objects( ([
   "/wiz/ice/obj/furniture/hmbed.c":1,
]) );

}
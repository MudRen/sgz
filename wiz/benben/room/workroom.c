#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief("--С�����ļ�--");
    set_long(
"С�����������˼ҵķ���ס�ģ��Լ����𷿣�ֻ����һ�����
���䲻�󣿿������ܼ򵥣����ò����ª��һ�Ŵ���һ����ױ�
̨��һ��д����������һ���輸����������Щ���ң�����С��
����̫����ʰ��\n\n����(window)\n\n");
    set_exits( ([
  "kitchen" : __DIR__+"room/kitchen.c",
        "bedroom" :  __DIR__+"room/bedroom.c",
        "out" :  FROOMPATH+"vzhu_lin.c"
    ]) );
    add_item("window" , "һ�����ϵĴ���",
        (["look" : "\n\n���汾���Ǵ󺣣�������ô���¥
��ʲô����ס�ˡ� :( \n\n"
        ]));
}                             


#include <mudlib.h>
#include <ansi.h>

inherit ROOM;

void setup(){
    set_area("huayin");
    set_light(50);
    set_brief("%^H_MAGENTA%^�ڽ�ͤ%^RESET%^");
    set_long("  

      ʤ�ܱ��Ҳ����ڣ������������ж���
      �����ӵܶ�ſ�����������δ��֪�� 
");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "wiz" :  "/domains/std/wizroom",
    ]) );
}

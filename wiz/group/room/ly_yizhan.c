////by ljty April,6 1998
// ��վ,ly_center.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
set_area("ly_area");
    set_light(1);
    set_brief(""+YEL+"��վ"+NOR+"");
    set_long("    �����������ǵ���վ��һ�������µ�������վ��̨ǰ��վ��
����һ��һ�����˻�����������ȥ����Ļ��������������\n\n");
    set_exits( ([
        "northeast" : __DIR__+"ly_ddj2.c",
    ]) );
   set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );

}

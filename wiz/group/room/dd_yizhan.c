////by ljty April,6 1998
// ��վ,dd_center.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
set_area("didao");
    set_light(1);
    set_brief(""+YEL+"��վ"+NOR+"");
    set_long("    �����ǵҵ�����վ��һ�������µ�������վ��̨ǰ��վ��
����һ��һ�����˻�����������ȥ����Ļ��������������\n\n");
    set_exits( ([
        "northeast" : __DIR__+"dd_yz.c",
    ]) );
   set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );

}

////by ljty April,6 1998
// ��վ,sd_center.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
set_area("sd_area");
    set_light(1);
    set_brief(""+YEL+"��վ"+NOR+"");
    set_long("    �������ϵ�����վ��һ�������µ�������վ��̨ǰ��վ��
����һ��һ�����˻�����������ȥ����Ļ��������������\n\n");
    set_exits( ([
        "northeast" : __DIR__+"sd_gz.c",
    ]) );
   set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );

}

////by ljty April,6 1998
// ��վ,jy_center.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
set_area("jy_area");
    set_light(1);
    set_brief(""+YEL+"��վ"+NOR+"");
    set_long("    �����������ǵ���վ��һ�������µ�������վ��̨ǰ��վ��
����һ��һ�����˻�����������ȥ����Ļ��������������\n\n");
    set_exits( ([
        "northeast" : __DIR__+"jy_czx.c",
    ]) );
   set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );

}

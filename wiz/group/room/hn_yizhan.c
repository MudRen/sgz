////by ljty April,6 1998
// ��վ,hn_center.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
set_area("hn_area");
    set_light(1);
    set_brief(""+YEL+"��վ"+NOR+"");
    set_long("    �����Ǻ�ũ�ǵ���վ��һ�������µ�������վ��̨ǰ��վ��
����һ��һ�����˻�����������ȥ����Ļ��������������\n\n");
    set_exits( ([
        "northeast" : __DIR__+"hn_cz.c",
    ]) );
   set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );

}

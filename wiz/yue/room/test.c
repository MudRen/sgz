//  С��
// vstore.c write by fire on 12.19.1997
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;
inherit STORE;

void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+YEL+"--���С��--"+NOR+"");
    set_long(
"    ���߽�����Ψһ��һ��С�꣬��Ϊ�������٣����������Ҳ��̫
�á���С���������������һ�Դ��˯�������һ���и���ˮ�ס���
�����Թ�ˮ��\n\n"
);
    set_exits( ([
        "east" :  __DIR__+"vcenter.c"
    ]) );
  add_object( FOBJPATH+"candy.c");
  add_object( FOBJPATH+"yangpi_jiudai.c");
  add_object( FOBJPATH+"huoba.c");
  add_object( FOBJPATH+"dart.c");
  set_objects( ([
                        FNPCPATH+"xiaoer" : 1,
  ]) );
}

#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"--�˼����ĵ�������--"+NOR+"");
    set_long(
"    �˼����ĵ�������ͦ����ġ���С��̫������ϴ����ȻҲ��Ū
���ࡣԡ�赹��С������������ͦ�����ܵġ�
\n");
    set_exits( ([
             "out" : "/wiz/ljty/workroom.c",
   ]) );
}

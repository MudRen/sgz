#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;	

void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"--�˼����ĵ�����--"+NOR+"");
    set_long(
"    �˼����ĵ������е����ң�˭�����Ż�û��λ��ƽ����������
˫�˴�����Ϣһ�»򿴿����ӡ�\n\n");
  set_objects(([
    "/wiz/ljty/obj/ljtybed.c" : 1
    ]) );
    set_exits( ([
             "down" : "/wiz/ljty/workroom.c",
   ]) );
}

#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
set_brief(""+HIR+"--�˼����ĵĳ���--"+NOR+"");
    set_long(
"    �ۣ��ô�ĳ��������������ﶼ��ʲô�������˼�����
������������������ӵ������ǣ������������ǲ��ù���
\n����(bingxiang)\n");
    set_exits( ([
             "out" : "/wiz/ljty/workroom.c",
   ]) );
  set_objects(([
    "/wiz/ljty/obj/foodgui.c" : 1
    ]) );
    add_item("bingxiang", "����",
            (["open" : "\n����һ�����У�ʧ���˰ɡ�\n\n",
              "look" : "\n�ô�ı��䣬�򿪿�����û�кܳԵ�\n\n",
           ]) );
}

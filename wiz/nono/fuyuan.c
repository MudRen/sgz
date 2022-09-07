#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

private mapping exits;

void bind_exit(string direction, object room, int both);
void setexits();


void setup()
{
    set_area("nono_room");
    set_light(50);
    set_brief(""+HIW+"��Ժ"+NOR+"");
    set_long(
"���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ����˵�ǵ���
��ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�һ�������ߵ�ͨ����Ժ�������Ҷ�����ɨ
�ء�");


    set_exits( (["enter" : "/wiz/nono/workroom.c",
                 "east" : "/wiz/nono/huayuan.c",
"out" : "/wiz/nono/gate.c",
                 ]) );              
}


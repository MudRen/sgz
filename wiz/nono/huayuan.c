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
    set_brief(""+HIW+"��԰"+NOR+"");
    set_long(
"���߽���Ժ�����Կ��Կ���һ���ŵĴ����������ŵ����Ư���ĵ����軨��ζ��
���в���һ���������������ܾ�ɫ�����������ˡ�ʯͤ����һ��ʯ��������ʯ
�ʣ�������Ϣ��");


    set_exits( (["west" : "/wiz/nono/fuyuan.c",
                  ]) );              
}



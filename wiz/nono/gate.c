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
    set_brief(""+HIW+"�����"+NOR+"");
    set_long(
"����վ��һ�������ĸ���ǰ����ͷ�ߴ��ʯʨ����ס�˴������࣬�����ϵ���
����������������ϸ���һ����ң����顸��ͤ����ĸ����֡��ſ�վ��
�������������Ž��£����ճ�ꪣ�������������");


    set_exits( (["enter" : "/wiz/nono/fuyuan.c",
                  ]) );              
}

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
    set_brief(""+HIW+"�鷿"+NOR+"");
    set_long(
"�����Ǻ���������Ƕ�����鷿���鰸�����ҵط��ż������ƵĹż�����ʮ
�������⣬��ɫ��Ͳ���ʺ��ڲ�ı�������һ����һ�����������һ����Ҥ��
�ң�����������ˮ����İ׾ջ����������ע���ȴ��ǽ�������ŵ��ǰѽ���");


    set_exits( (["east" : "/wiz/nono/workroom.c",
                  ]) );              
}



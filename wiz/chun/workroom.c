/* workroom.c
** Coded by ����@����
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>

inherit INDOOR_ROOM;

void setup(){
    set_area("westside");
    set_light(20);
        set_brief(""+HIR+"ů���"+NOR+"");
    set_long("
    ů�����ֻ��һ�����������ż�֧ë�ʣ��տյ��������
��Ȼ���ӵ�Ů���˲���ϲ��֬֬�۷ۡ�Ȼ����ֵ�������������Ȼ
ɢ����һ�����㡣
\n\n"
);
    set_exits( ([
	"out" : __DIR__+"park.c",
    ]));
    set_objects( ([
  __DIR__+"shabed.c":1,
    ]) );
}

int smell()
{
    write ("һ�ɲ�֪���������˱Ƕ��룬���������㲻�ɵĳ��ˡ�����\n");
    return 1;
}

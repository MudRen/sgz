// �ҵ�����
// dd_xy.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"����"+NOR+"");
    set_long("  ǰ���Ѿ�û��·�ˣ���ɽ������һ��������̽����ͷ������
�������ң�ʲô������������������ڶ��ߣ�һ˿�־�ӵ��
��ͷ������֪Ϊʲô���и�����ȥ�ĳ嶯���������ձ��ܣ�
�����絽���˽������
\n\n");
    set_exits( ([
        "southwest" :  __DIR__+"dd_wl.c",
        "south"     :  __DIR__+"dd_dl.c",
	"east"      :  __DIR__+"dd_sy.c",
    ]) );
}



// �ҵ�Сɽͷ
// dd_dl.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"Сɽͷ"+NOR+"");
    set_long("  һ��С·ֱͨ��һƬ�����ĵط����ѵ��Ǿ��ǳ��ڡ��Ա߻���
һ���ܶ��˲ȹ���С���������������������ġ�\n\n");
    set_exits( ([
        "northwest" :  __DIR__+"dd_wl.c",
        "north" :  __DIR__+"dd_xy.c",
        "south" :  __DIR__+"dd_xst.c",
    ]) );
}

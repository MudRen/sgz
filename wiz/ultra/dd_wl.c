// �ҵ���·
// dd_wl.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"��·"+NOR+"");
    set_long("  �����оŰپ�ʮ�Ÿ��ǣ��ҵ��оŰپ�ʮ�Ÿ��䡣
�䲻��������ˮ��������������ľ����һ��һ�����䣬
����ս���ļ�����δ����·���������ģ���������!\n\n");
    set_exits( ([
        "southeast" :  __DIR__+"dd_dl.c",
        "northeast" :  __DIR__+"dd_xy.c",
        "west" :  __DIR__+"dd_dkx.c",
    ]) );
}

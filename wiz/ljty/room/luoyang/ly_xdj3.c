//  �������
// ly_xdj3.c described by ljty 1.8.1998
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ly_area");
    set_light(50);
    set_brief(""+YEL+"�����"+NOR+"");
    set_long("    ����������ֵľ�ͷ��������ɵ������ǵ��������ˡ�Զ������
�ٱ���ߺ���������Զ�֪�ٱ��������������������������ˡ�������һ
��ţ���ʱ�м���ţ�д������ϱ�����С���ӣ������������˲��١�
\n\n");
    set_exits( ([
        "west" :  __DIR__+"ly_xicm.c",
        "east" :  __DIR__+"ly_xdj2.c",
        "north" :  __DIR__+"ly_niup.c",
        "south" :  __DIR__+"ly_chengxx.c",
    ]) );
}

// ��ͤУ���� 
// jt_xjc.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"��ͤУ����"+NOR+"");
    set_long(" ��ͤ��С��ȴ��ϵ���أ�����κ��ͨ���ʺ�Ҫ������Ϊ���ұ���֮
������һ��Ƭ�յ��ϣ�����ʿ�����ڲ����������ǽ�ͤ��У������
ƽʱ���������ĺͼ��϶������������פ�������ĵط����ϱ߾�
�����������פ������\n\n");
    set_exits( ([
        "north" :  __DIR__+"jt_jying.c",
        "east" :  __DIR__+"jt_lcao.c",
    ]) );
}



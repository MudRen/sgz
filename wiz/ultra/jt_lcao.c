// ��ͤ�����ͻ���
// jt_lcao.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"�����ͻ���"+NOR+"");
    set_long("   ��ͤפ���ͻ����ݵĵط����б�ʿ���������û�����ݣ���������ֻ�����־����ˡ�\n\n");
    set_exits( ([
        "west" :  __DIR__+"jt_area.c",
    ]) );
}



#include <mudlib.h>
#include <ansi.h>
inherit ROOM;
void setup()
{
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"����ׯ"+HIY+"�����ֺ�Ժ"+NOR+"");
    set_long("
��Ժ������ϣ���Ȼ��������������ִ�����ӣ�ժ��������
����װ��ʮ¨������ȥӦ��������ʮ�����ӡ�
��Լ�����������ˣ��޿��κε�˵���������Ƕ��ܳ���ȥ�ˡ�
���������Ժ������ɡ���\n\n");
    set_exits ((["out"       :  "/wiz/shaoyng/workroom.c",
                 "xiliang"   :  "/sgdomain/area/cities/xiliang/xiliang_M.c"
                ]) );
    set_hidden_exits("xiliang");
    set_objects (([ "/wiz/shaoyng/npc/jiangwei.c" : 1 ]));
}                             



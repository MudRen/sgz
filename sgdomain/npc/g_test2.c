// g_test2.c "���"
#include <mudlib.h>
#include <ansi.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void setup()
{
    set_name("liumei", "���");
    set_gender(0);
    set_proper_name("���");
    set_in_room_desc("���� "+MAG+"���"+NOR+"(liumei)");
    set_long("��һ��Բ����������üë��������໹��һ��С�룬
���ǿɰ�֮����������һ���������ף�˫�ֲ�ͣ
������һֻ���ʣ��������㿴�������е���š�");
     add_pattern("%sͻȻ������һ�������С�",function(){
        if ($1=="����")
        {
                respond("say ����������ˣ��˼ҵ�����һ�����ˡ�");
        }
        else
        {
                respond("say �㿴������û�У�");
        }
        });
}

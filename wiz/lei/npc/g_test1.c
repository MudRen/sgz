// g_test1.c "����С�"
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
    set_name("bamei", "С�");
    set_gender(0);
    set_proper_name("С�");
    set_in_room_desc("���� "+MAG+"С�"+NOR+"(bamei)");
    set_long("������΢΢����ͷ������ɬ�Ŀ��ű��ˡ�������
�¿ڴ������һ��ǳ��ɫ�ıʼǱ�����ǰ����һ֧
�ֱʣ������ʱ��׼��дЩʲô��");
     add_pattern("%sͻȻ������һ�������С�",function(){
        if ($1=="����")
        {
                respond("say �磬������ˡ�");
        }
        else
        {
                respond("smile");
        }
        });
}

#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>

inherit M_WEARABLE;
inherit M_GETTABLE;

void setup()
{
        ::mudlib_setup();
        set_unit("��");  
        set_id("flower", "�ʻ�");
        set_long("һ�����ʵĻ����������ǳ��㡣");
        set_in_room_desc("�ʻ�(flower)");
        set_gettable(1);
        set_slot(HEAD); 
        set_wearmsg("$N���˵��������ʻ�����������ͷ�ϣ�����Ư������ࡣ\n");
        set_removemsg("$N����ذ�һ���ʻ���ͷ��ȡ�¡�\n");
}
 

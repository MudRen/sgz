#include <mudlib.h>
inherit LIVING;


//override this function then this npc can use delay_d.
object query_body()
{
return this_object();
}

void setup()
{
    set_name("turf boss", "�����ϰ�");
    add_id("boss");
    set_gender(1);
    set_proper_name("�����ϰ�");
    set_in_room_desc("�����ϰ�(turf boss)");
    set_long("�����ϰ�Ц��ӯӯ�ؿ����㣬�������һ�ֲ���һ�Ѳ�����˼�ĸо�����");
}

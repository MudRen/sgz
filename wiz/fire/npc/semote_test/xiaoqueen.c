#include <mudlib.h>
#include <sanguo.h>
inherit MONSTER;
void setup()
{
    set_name("xiao huanghou", "���ʺ�");
    add_id("xiao"); 
    add_id("huanghou");
    set_gender(2);
    set_proper_name("���ʺ�");
    set_in_room_desc("���ʺ�(xiao huanghou)");
    set_age(70);
    set_sg_rank(R_KING);
    set_shengwang(10000000);
}
